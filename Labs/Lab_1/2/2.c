#include <stdio.h>
#include <math.h> // новая библиотека для sqrt
int main() {
    printf("Please enter a number:");
    int num, i, is_prime = 1; // i-счётчик, тоесть в цикле для того, чтобы понять являеться ли число простым я сразу убераю двойку и иду до корня из числа. is_prime - это флаг, который позволяет нам определить являеться ли чилсо простым. Если он остаёться как 1, то число prime, в противном случае not prime.
    if (scanf("%d", &num) != 1 || num <= 0) // != 1 означает, что елси scanf не вернул единицу, тоесть не считал то, что ввели за число. Например ввели abc он вернёт 0, а это не равно единице и соответственно будет исполненно другое условие.
    {
        printf("You type not a number or your number is lower or same as 0 and I can't calculate it.\n");
    }
    else
    {
        if(num == 1)
        {
            printf("Number is not an prime or composite!\n");
        }
        else
        {
            for(i = 2; i <= (int)sqrt(num); i++) //sqrt возвращает вещественное число формата double
            {
                if(num % i == 0)
                {
                    is_prime = 0;
                    break;
                }

            }
            if (is_prime == 0)               
            {
                printf("%d is composite\n", num);
            }
            else
            {
                printf("%d is prime\n", num);
            }
        }
    }    
    return 0;
}