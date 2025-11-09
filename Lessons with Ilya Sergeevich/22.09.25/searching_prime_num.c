#include <stdio.h>
int main() {
    printf("Please enter number:");
    int num1, i, is_prime = 1;
    if (scanf("%d", &num1) != 1 || num1 <= 0)
    {
        printf("Incorrect number");
    }
    else
    {
        if(num1 == 1)
        {
            printf("Number is not an prime or composite");
        }
        else
        {
            for(i = 2; i*i <= num1; i = i + 1)
            {
                if(num1 / i == 0)
                {
                    is_prime = 0;
                    break;
                }

            }
            /*if (is_prime == 0)               
            {
                printf("is composite");
            }
            else
            {
                printf("is prime\n");
            }*/
            printf("is %s", is_prime == 0
                ? "composite\n"
                : "prime\n");
        }
    }    


    return 0;
}

// i -  счётчик 
// num1 - число которое мы проверяем простое оно или составное