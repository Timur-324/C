#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


typedef struct student
{
    char *surname;
    char *name;
    char *patronymic;
    size_t age;
    char sex;
    char *group_name;
} student, *p_student;


void tuned_free_all(void **to_free, ...) 
{
    if (!to_free) return;

    free(*to_free);
    *to_free = NULL;

    va_list va;
    va_start(va, to_free);
    void **from_va;
    while ((from_va = va_arg(va, void**)) != NULL) {
        free(*from_va);
        *from_va = NULL;
    }
    va_end(va);
}

//Освобождение памяти структуры student
void free_student(p_student stud_ptr) 
{
    if (!stud_ptr) return;
    tuned_free_all(
        (void **)&stud_ptr->surname,
        &stud_ptr->name,
        &stud_ptr->patronymic,
        &stud_ptr->group_name,
        NULL
    );
}


int init_string_at_heap(char **to_init, const char *source) 
{
    if (!to_init || !source) return 1;
    
    *to_init = (char *)malloc(strlen(source) + 1);

    if (!*to_init) return 1;
    
    strcpy(*to_init, source);
    return 0;
}

int main()
{
    student stud_instance;

    if (init_string_at_heap(&stud_instance.surname, "Sadykov") != 0) 
    {
        printf("Error! Can not allocate memory for surname.");
        return -1;
    }
    
    if (init_string_at_heap(&stud_instance.name, "Timur") != 0) 
    {
        free_student(&stud_instance);
        printf("Error! Can not allocate memory for name.");
        return -2;
    }
    
    if (init_string_at_heap(&stud_instance.patronymic, "Eduardovich") != 0)
    {
        free_student(&stud_instance);
        printf("Error! Can not allocate memory for patronymic.");
        return -3;
    }
    
    if (init_string_at_heap(&stud_instance.group_name, "ITPM-125") != 0) 
    {
        free_student(&stud_instance);
        printf("Error! Can not allocate memory for group.");
        return -4;
    }

    stud_instance.age = 17;
    stud_instance.sex = 'M';


    printf("SNP: %s %s %s\n", stud_instance.surname, stud_instance.name, stud_instance.patronymic);
    printf("Age: %zu\n", stud_instance.age);
    printf("Group: %s\n", stud_instance.group_name);

    free_student(&stud_instance);

    return 0;
}