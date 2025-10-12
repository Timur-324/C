#include <stdio.h> // в теории сюда ещё можно добавить другую библиотеку <gmp.h> для того, чтобы можно было возводить в ещё большую степень и с ещё большими числами. int не бесконечный и при больший конечных значениях в ответе может быть отрицательное число.
int power_f(int num, int power)
{
    int result_of_multiplication = 1;
    while(power != 0)
    {
        if(power % 2 == 1)
        {
            result_of_multiplication *= num;
        }
        num *= num;
        power /= 2;
    }
    return result_of_multiplication;
}

int main()
{
    printf("Please enter a number and power that you want to apply to a number:\n");
    int num, power;
    if (scanf("%d%d", &num, &power) != 2)
    {
        printf("You typed not a number!\n");
    }
    else
    {
        printf("Your number %d in %d power = %d\n", num, power, power_f(num, power));
    }
    return 0;
}