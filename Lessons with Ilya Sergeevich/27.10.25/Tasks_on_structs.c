#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>
#include <stdarg.h>
#include <string.h>



void tuned_free_all(
    void** to_free,
    ...);

typedef struct student
{
    char *surname;
    char *name;
    char *patronymic;
    size_t age;
    char sex;
    char *group_name;
} student, stud, *p_student;

void free_student(
    p_student stud_ptr)
{
    tuned_free_all((void **)&stud_ptr->surname, &stud_ptr->name, &stud_ptr->patronymic, &stud_ptr->group_name, NULL);
}


void free_all(
    void* to_free,
    ...)
{
    if (to_free == NULL)
    {
        return;
    }

    free(to_free);

    va_list va;
    va_start(va, to_free);
    void *from_va;

    while ((from_va = va_arg(va, void*)) != NULL)
    {
        free(from_va);
    }
}

void tuned_free_all(
    void **to_free,
    ...)
{
    if (to_free == NULL)
    {
        return;
    }

    free(*to_free);
    *to_free = NULL;

    va_list va;
    va_start(va, to_free);
    void** from_va;

    while ((from_va = va_arg(va, void**)) != NULL)
    {
        free(*from_va);
        *from_va = NULL;
    }
}

int main(
    int argc,
    char* argv[])
{
    student stud_instance;
    stud_instance.age = 17;

    stud_instance.surname = (char *)malloc(sizeof(char) * (strlen("Sadykov") + 1));
    if (stud_instance.surname == NULL)
    {
        return 1;
    }
    strcpy(stud_instance.surname, "Sadykov");

    stud_instance.name = (char*)malloc(sizeof(char) * (strlen("Timur") + 1));
    if (stud_instance.name == NULL)
    {
        free(stud_instance.surname);
        return 1;
    }
    strcpy(stud_instance.surname, "Timur");

    stud_instance.patronymic = (char*)malloc(sizeof(char) * (strlen("Eduardovich") + 1));
    if (stud_instance.patronymic == NULL)
    {
        // free(stud_instance.surname);
        // free(stud_instance.name);
        free_all(stud_instance.surname, stud_instance.name, NULL);
        return 1;
    }
    strcpy(stud_instance.surname, "Eduardovich");

    stud_instance.group_name = (char*)malloc(sizeof(char) * (strlen("ITPM-125") + 1));
    if (stud_instance.group_name == NULL)
    {
        // free(stud_instance.surname);
        // free(stud_instance.name);
        // free(stud_instance.patronymic);
        free_all(stud_instance.surname, stud_instance.name, stud_instance.patronymic, NULL);
        return 1;
    }
    strcpy(stud_instance.surname, "ITPM-125");

    stud_instance.sex = 52;

    printf("sizeof(puk_srenjk) == %u\n", sizeof(struct puk_srenjk));
    printf("sum of sizeofs of char and int == %u", sizeof(char) + sizeof(int));

    free_student(&stud_instance);

    // TODO: usage of initialized struct instance...

    // TODO: make this at home
    // int init_string_at_heap(
    //    char** to_init,
    //    char const* source);

    return 0;
}