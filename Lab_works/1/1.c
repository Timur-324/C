// TEST!!!!


#include <stdio.h>
#include <math.h>
// оговорочка, так как я использую тип int в функциях если num будет реально большое, то 
//  проверка на полный квадрат
int num_is_perfect_square(int num_in_the_formula_that_we_need_to_find_perfect_square) // num=3 ==> 5*(num*num) +- 4 = num_in_the_formula_that_we_need_to_find_perfect_square
{
    int check;
    check = sqrt(num_in_the_formula_that_we_need_to_find_perfect_square);
    return check*check == num_in_the_formula_that_we_need_to_find_perfect_square; // тут возвращает 1 или 0
}


// функция на проверку числа: являеться ли число числом Фибоначи
int is_fibonacci(int num) 
{
    return num_is_perfect_square(5 * num * num + 4) || num_is_perfect_square(5 * num * num - 4); // а тут нам нужно, чтобы хотябы в одном из выражений была единица, так как если изхода из формулы Бине одно из них будет верно, то число являеться числом фибоначи
}


int main() 
{
    int num1, num2, num3;
    printf("Hello! In this programm you can check:\na) is your numbers could be an side of a triangle\nb) is your numbers could be a side of a right triangle\nc) is your numbers could be an elements of an arithmetic progression\nd) is your numbers could be an elements of an geometric progression\ne) is your numbers could be an elements of Fibonacci\nf) is your numbers could be a consecutive elements of the Fibonacci sequence");
    printf("\nPrint three not negative numbers:\n");
    if (scanf("%d%d%d", &num1, &num2, &num3) != 3)
    {
        printf("You type not a number or your numbers is neagative.\n");
    }
    else
    {
    // a)
        if (num1 > 0 && num2 > 0 && num3 > 0 && 
            num1 + num2 > num3 &&
            num1 + num3 > num2 &&
            num2 + num3 > num1)
        {
            printf("Yes, your numbers can be a sides of triangle.\n");
        }
        else
        {
            printf("No, your numbers can't be a sides of triangle.\n");
        }
        
    // b)

        if (num1 > 0 && num2 > 0 && num3 > 0 && 
            num1*num1 + num2*num2 == num3*num3 &&
            num1*num1 + num3*num3 == num2*num2 &&
            num2*num2 + num3*num3 == num1*num1)
        {
            printf("Yes, your numbers can be a side of a right triangle.\n");
        }
        else
        {
            printf("No, your numbers can't be a side of a right triangle.\n");
        }

    // c)

        if (2*num2 == num1 + num3)
        {
            printf("Yes, your numbers can be an elements of an arithmetic progression.\n");
        }
        else
        {
            printf("No, your numbers can't be an elements of an arithmetic progression.\n");
        }

    // d)

        if (num2*num2 == num1 * num3)
        {
            printf("Yes, your numbers can be an elements of an geometric progression.\n");
        }
        else
        {
            printf("No, your numbers can't be an elements of an geometric progression.\n");
        }


    // e) + f) для того, чтобы понять являеться ли число числом фибоначи нам нужно пройти по формуле Бине


        if (is_fibonacci(num1) && is_fibonacci(num2) && is_fibonacci(num3))
        {
            printf("Yes, your numbers is an elements of Fibonacci.\n");
            if(num3 == num1 + num2)
            {
                printf("Yes, your numbers can be a consecutive elements of the Fibonacci sequence.\n");
            }
            else
            {
                printf("No, your numbers can't be a consecutive elements of the Fibonacci sequence.\n");
            }
        }
        else
        {
            printf("No, your numbers is an elements of Fibonacci.\n");
            printf("No, your numbers can't be a consecutive elements of the Fibonacci sequence.\n");
        }
    }
    return 0;
}