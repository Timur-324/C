#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

int fibonacci(int n) 
{
    if(n < 0){ return -1;}
    if (n == 0) 
    {
        return 0;
    } 
    else if (n == 1) 
    {
        return 1;
    } 
    else 
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int Fibonacci_sequence(int *DA, int n)
{
    if(DA == NULL){ return -1;}
    if(n < 0){ return -2; }
    int i;
    int fibonacci_result;
    for(i = 0; i <= n; i++)
        {
            fibonacci_result = fibonacci(i);
            DA[i] = fibonacci_result;
        }
    return 0;
}



int main()
{
    int *dyn_array;
    int n;
    int i;
    printf("Enter a number of how much values of Fibonacci sequence you want to see:\n");
    while(scanf("%d", &n) != 1)
    {
       printf("Error! :[ \nPlease type your number again:\n");
        while(getchar() != '\n');
    }
//    switch (fibonacci(-2))
//    {
//    case -1:
//     printf("You entered an invalid argument!\n");
//     break;
//    }

    if((dyn_array = (int *)malloc(sizeof(int) * (size_t)n)) == NULL)
    {
        printf("Can not allocate memory for dynamic array!\n");
        return 1;
    }

    switch (Fibonacci_sequence(dyn_array, n))
    {
    case -1:
        printf("You have presented an invalid pointer to a dynamic array!\n");
        return -2;
        break;
    case -2:
        printf("You entered invalid argument!\n");
        return -3;
        break;
    case 0:
        for(i = 0; i < n; ++i)
        {
            printf("%d\n", dyn_array[i]);
        }

        free(dyn_array);
        break;
    }

    return 0;
}