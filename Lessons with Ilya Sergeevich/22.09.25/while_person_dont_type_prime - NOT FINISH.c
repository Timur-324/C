#include <stdio.h>
int main()
{
    while (1)
    {
        int value_45, maybe_prime;
        printf("Enter number:");
        if(scanf("%d", value_45) != 1 || value_45 <= 0)
        {
            printf("invalid input!!!");
            continue;
        }
        if(maybe_prime == 1)
        {
            printf("Input number is not prime");
        }
        else
        {
            for(i = 2; i*i <= maybe_prime; i = i + 1)
            {
                if(num1 / i == 0)
                {
                    is_prime = 0;
                    break;
                }
        }
    }
    return 0;
}
