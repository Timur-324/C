#include <stdio.h>
void swap_num(int* num1, int* num2)
{
    int temporary_memory_storage;
    temporary_memory_storage = *num1;
    *num1 = *num2;
    *num2 = temporary_memory_storage;

}

int main()
{
    int num1, num2;
    printf("Hello! I want to demonstare you how pointers work in C.\nPlease type two different numbers:");
    if (scanf("%d%d", &num1, &num2) != 2)
    {
        printf("You typed not a number!\n");
    }
    else
    {
        printf("You choose %d and %d.\n", num1, num2);
        swap_num(&num1, &num2);
        printf("Now with function and pointers we have your first number that is equal %d and second is %d.\n", num1, num2);

    }
    return 0;
}