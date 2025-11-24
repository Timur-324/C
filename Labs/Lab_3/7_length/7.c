#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 100
#define MAX_MEASUREMENTS 1000

typedef struct Measurement
{
    double value;
    char unit[10];
    double value_in_meters;
} Measurement, M;

double convert_to_meters(double value, const char *unit) 
{
    //number is not NaN and infinity
    if (isnan(value) || isinf(value)) 
    {
        return -1.0;
    }

    //we need good unit and not bullshit
    if (strcmp(unit, "m") != 0 &&
        strcmp(unit, "cm") != 0 &&
        strcmp(unit, "ya") != 0 &&
        strcmp(unit, "ft") != 0 &&
        strcmp(unit, "lok") != 0 &&
        strcmp(unit, "ver") != 0 &&
        strcmp(unit, "arsh") != 0 &&
        strcmp(unit, "sazh") != 0) 
    {
        return -2.0;
    }
    if (strcmp(unit, "m") == 0) return value;
    else if (strcmp(unit, "cm") == 0) return value * 0.01;
    else if (strcmp(unit, "ya") == 0) return value * 0.9144;
    else if (strcmp(unit, "ft") == 0) return value * 0.3048;
    else if (strcmp(unit, "lok") == 0) return value * 0.4572;
    else if (strcmp(unit, "ver") == 0) return value * 0.04445;
    else if (strcmp(unit, "arsh") == 0) return value * 0.7112;
    else if (strcmp(unit, "sazh") == 0) return value * 2.1336;
    return 0.0;
}

int compare_measurements(const void *a, const void *b)
{
    if(a == NULL || b == NULL)
    {
        return -2;
    }

    M *m1 = (M *)a;
    M *m2 = (M *)b;

    if (m1->value_in_meters > m2->value_in_meters)
    {
        return 1;
    }
    else if (m1->value_in_meters < m2->value_in_meters)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}


int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        printf("Error! Not enough arguments!\n");
        return -1;
    }

    FILE *file;
    if((file = fopen(argv[1], "r+")) == NULL)
    {
        printf("File did not opened!\n");
        return -2;
    }

    M measurements[MAX_MEASUREMENTS];
    int count = 0;
    char line[MAX_LINE_LENGTH];
    double temp_value;


    while (fgets(line, sizeof(line), file) != NULL) 
    {
        if (sscanf(line, "%lf %s", &measurements[count].value, measurements[count].unit) == 2) 
        {
            if (strcmp(measurements[count].unit, "m") != 0 &&
                strcmp(measurements[count].unit, "cm") != 0 &&
                strcmp(measurements[count].unit, "ya") != 0 &&
                strcmp(measurements[count].unit, "ft") != 0 &&
                strcmp(measurements[count].unit, "lok") != 0 &&
                strcmp(measurements[count].unit, "ver") != 0 &&
                strcmp(measurements[count].unit, "arsh") != 0 &&
                strcmp(measurements[count].unit, "sazh") != 0) 
            {
                printf("Error! Wrong units in the file!\n");
                return -3;
            }
            else
            {
                temp_value = convert_to_meters(measurements[count].value, measurements[count].unit);
                if(temp_value != -1.0 || temp_value != -2.0)
                {
                    measurements[count].value_in_meters = temp_value;
                    count++;
                }
                else
                {
                    printf("You put NaN or infinity in func or your unit is bullshit.\n");
                }
            }
        }
        else
        {
            printf("Error! Wrong measurments in the file or not enough arguments in the line!\n");
            return -4;
        }
    }

    qsort(measurements, count, sizeof(M), compare_measurements);

    rewind(file);
    for (int i = 0; i < count; ++i) 
    {
        fprintf(file, "%.0lf %s\n", measurements[i].value, measurements[i].unit);
    }

    fclose(file);
    return 0;
}