#include <stdio.h>
#include <string.h>

// typedef int student; - тут по сути даю другое название типу int

typedef struct 
{
    char name[50];
    char id[10];
    int age;
    int grades[5];

}student; //дал название student всей структуре

void print_el_of_struct(student student) //второй student это 
{
    printf("Name: %s\n", student.name);
    printf("ID: %s\n", student.id);
    printf("Age: %d\n", student.age);
    printf("Grades: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", student.grades[i]);
    }
    printf("\n");
}



int main()
{
    student Timur;

    Timur.age = 17;
    strcpy(Timur.name, "Timur");
    strcpy(Timur.id, "0001");
    Timur.grades[0] = 4;
    Timur.grades[1] = 5;
    Timur.grades[2] = 4;
    Timur.grades[3] = 4;
    Timur.grades[4] = 5;

    print_el_of_struct(Timur);
}