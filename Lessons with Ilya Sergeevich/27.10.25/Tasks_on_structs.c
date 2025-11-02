#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// Структура студента
typedef struct student
{
    char *surname;
    char *name;
    char *patronymic;
    size_t age;
    char sex;
    char *group_name;
} student, *p_student;

// Универсальная функция освобождения памяти и обнуления указателей
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

// Освобождение всех полей структуры student
void free_student(p_student stud_ptr) {
    if (!stud_ptr) return;
    tuned_free_all(
        (void **)&stud_ptr->surname,
        &stud_ptr->name,
        &stud_ptr->patronymic,
        &stud_ptr->group_name,
        NULL
    );
}

// Удобная функция для инициализации строки в динамической памяти
// Возвращает 0 — успех, 1 — ошибка (память не выделена)
int init_string_at_heap(char **to_init, const char *source) 
{
    if (!to_init || !source) return 1;
    *to_init = malloc(strlen(source) + 1);
    if (!*to_init) return 1;
    strcpy(*to_init, source);
    return 0;
}

int main(void) {
    student stud_instance = {0}; // Надежная инициализация нулями

    // Инициализация полей. Проверка ошибок на каждом этапе.
    if (init_string_at_heap(&stud_instance.surname, "Sadykov") != 0) {
        puts("Ошибка выделения памяти для фамилии.");
        return 1;
    }
    if (init_string_at_heap(&stud_instance.name, "Timur") != 0) {
        free_student(&stud_instance);
        puts("Ошибка выделения памяти для имени.");
        return 1;
    }
    if (init_string_at_heap(&stud_instance.patronymic, "Eduardovich") != 0) {
        free_student(&stud_instance);
        puts("Ошибка выделения памяти для отчества.");
        return 1;
    }
    if (init_string_at_heap(&stud_instance.group_name, "ITPM-125") != 0) {
        free_student(&stud_instance);
        puts("Ошибка выделения памяти для группы.");
        return 1;
    }

    stud_instance.age = 17;
    stud_instance.sex = 'M'; // Для примера, корректный символ

    // Пример использования:
    printf("ФИО: %s %s %s\n", stud_instance.surname, stud_instance.name, stud_instance.patronymic);
    printf("Возраст: %zu\n", stud_instance.age);
    printf("Группа: %s\n", stud_instance.group_name);

    // Освобождение памяти централизовано
    free_student(&stud_instance);

    return 0;
}