#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>

//Основная функция
void aghm(double *arith, double *geom, double *harm, double *median, size_t count, ...) 
{
    va_list args;
    va_start(args, count);
    double *median_arr; //{1, 2, 3, 4, 5} - 3 median
    double sum = 0.0; //сумма всех чисел - нужно для среднего арифметического
    double prod = 1.0; //произведение 
    double inv_sum = 0.0; //сумма обратных величин - нужна для среднего гармонического
    size_t i, j;
    double value;
    double temp;

    //Динамический массив для нахождения медианы 
    median_arr = (double *)malloc(count * sizeof(double));
    if (median_arr == NULL) 
    {
        printf("Error! Can not allocate memory.\n");
        va_end(args);
        return;
    }


    //Считаю сумму, произведение, inv_sum для среднего гармонического и заполняем дин.массив для медианы
    for (i = 0; i < count; i++) 
    {
        value = va_arg(args, double);
        sum += value;
        prod *= value;
        inv_sum += 1.0 / value;
        median_arr[i] = value;
    }
    va_end(args);

    // Среднее арифметическое
    *arith = sum / count;


    // Среднее геометрическое
    *geom = pow(prod, 1.0 / count); //pow(base, exp)


    // Среднее гармоническое
    *harm = count / inv_sum;


    //Медиана
    //Пузырькова сортировка
    for (i = 0; i < count - 1; i++) 
    {
    for (j = 0; j < count - i - 1; j++)
        {
            if (median_arr[j] > median_arr[j + 1])
            {
                temp = median_arr[j];
                median_arr[j] = median_arr[j + 1];
                median_arr[j + 1] = temp;
            }
        }
    }

    if (count % 2 == 0)
        *median = (median_arr[count/2 - 1] + median_arr[count/2]) / 2.0;
    else
        *median = median_arr[count/2];

    free(median_arr);
}




int main() 
{
    double arth_prog, geom_prog, harmonic, median;

    aghm(&arth_prog, &geom_prog, &harmonic, &median, 5, 1.0, 2.0, 3.5, 4.0, 10.0);


    printf("Arithmetic avarage: %f\n", arth_prog);
    printf("Geometries avarage: %f\n", geom_prog);
    printf("Harmonic avarage: %f\n", harmonic);
    printf("Median: %f\n", median);

    return 0;
}