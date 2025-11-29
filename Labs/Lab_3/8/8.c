#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int isPrime(int number) 
{
    if (number < 2) 
    {
        return -1;
    }
    int divisor;
    for (divisor = 2; divisor * divisor <= number; divisor++) 
    {
        if (number % divisor == 0) 
        {
            return -1;
        }
    }
    return 0;
}


int sumBase10(int number) 
{
    if(number < 1){return -1;}
    int sum = 0;
    while (number > 0) 
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}


int prodBase(int number, int base) 
{
    if(number < 1 || base < 1) {return -1;}
    int product = 1;
    int digit;
    while (number > 0) 
    {
        digit = number % base;
        product = product * digit;
        number /= base;
    }
    return product;
}


int isPalindBase(int number, int base) 
{
    if(number < 1 || base < 1) {return -1;}
    unsigned int digits[64];
    unsigned int digitCount = 0;
    unsigned int i;

    while (number > 0) 
    {
        digits[digitCount++] = number % base;
        number /= base;
    }
    if (digitCount == 0) 
    {
        return -2;
    }
    for (i = 0; i < digitCount / 2; i++) 
    {
        if (digits[i] != digits[digitCount - i - 1]) 
        {
            return -3;
        }
    }
    return 0;
}


int main(int argc, char *argv[]) 
{
    if (argc != 3) 
    {
        printf("Error! Not enough arguments!");
        return -1;
    }

    int limit;
    int base;
    int i;
    if (sscanf(argv[1], "%d", &limit) != 1 || limit < 1) 
    {
    printf("Error: N must be a natural number (> 0).\n");
    return -2;
    }

    if (sscanf(argv[2], "%d", &base) != 1 || base < 2 || base > 36) 
    {
        printf("Error: base must be in range 2..36.\n");
        return -3;
    }

    //a
    printf("a. Prime numbers: \n");
    for (i = 1; i <= limit; i++) 
    {
        if (isPrime(i) == 0) 
        {
            printf("%d ", i);
        }
    }
    printf("\n\n");

    //b 
    printf("b. Sum of base10 digits is prime:\n");
    for (i = 1; i <= limit; i++) 
    {
        if (isPrime(sumBase10(i)) == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n\n");

    //c
    printf("c. Product of digits in base is prime:\n");
    for (i = 1; i <= limit; i++) 
    {
        if (isPrime(prodBase(i, base)) == 0) 
        {
            printf("%d ", i);
        }
    }
    printf("\n\n");


    //d
    printf("Product of digits in base is not prime:\n");
    for (i = 1; i <= limit; i++) 
    {
        if (isPrime(prodBase(i, base)) != 0) 
        {
            printf("%d ", i);
        }
    }
    printf("\n\n");
    
    //e
    printf("Palindromes in base:\n");
    for (i = 1; i <= limit; i++)
    {
        if (isPalindBase(i, base) == 0) 
        {
            printf("%d ", i);
        }
    }
    printf("\n\n");

    //f
    printf("Sophie Germain primes:\n");
    for (i = 1; i <= limit; i++) 
    {
        if (isPrime(i) && isPrime(2 * i + 1)) 
        {
            printf("%d ", i);
        }
    }
    printf("\n\n");
    return 0;
}