#include <stdio.h>
#include <string.h>

// typedef int student; - тут по сути даю другое название типу int

struct sudent //fist variant on how to use struct
{
    char name[50];
    char id[10];
    int age;
    int grades[5];

};

int main()
{
    struct student Timur;

    Timur.age = 17;

    strcpy(Timur.name, "Timur");
    strcpy(Timur.id, "0001");
    Timur.grades[0] = 4;
    Timur.grades[1] = 5;
    Timur.grades[2] = 4;
    Timur.grades[3] = 4;
    Timur.grades[4] = 5;

    printf("Name: %s\n", Timur.name);
    printf("ID: %s\n", Timur.id);
    printf("Age: %d\n", Timur.age);
    printf("Grades: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", Timur.grades[i]);
    }
    printf("\n");


}