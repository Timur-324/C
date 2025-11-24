#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void convert_to_base(int number, int base, int *digits, int *digit_count) 
{
    *digit_count = 0;
    if (number == 0) 
    {
        digits[(*digit_count)++] = 0;
        return;
    }
    while (number > 0) 
    {
        digits[(*digit_count)++] = number % base;
        number /= base;
    }
    // Реверсируем массив
    for (int i = 0; i < *digit_count / 2; ++i) 
    {
        int temp = digits[i];
        digits[i] = digits[*digit_count - 1 - i];
        digits[*digit_count - 1 - i] = temp;
    }
}


void print_histogram(int *digits, int digit_count, int base)
{
    int frequency[36] = {0}; // Максимум 36 цифр для системы base <= 36

    for (int i = 0; i < digit_count; ++i) 
    {
        frequency[digits[i]]++;
    }

    for (int i = 0; i < base; ++i) 
    {
        if (frequency[i] > 0) // Проверяем, есть ли такая цифра
        {
            printf("%d ", i);
            for (int j = 0; j < frequency[i]; ++j) 
            {
                printf("*");
            }
            printf("\n");
        }
    }
}

int main()
{
    int UN; // UN - user number
    char str_UN[BUFSIZ];
    int isValid = 1; 
    int length_str_UN;
    int i;
    int base;
    int digit_count;
    int digits[BUFSIZ];

    printf("Hello!\nType number in decimal base and and in the range from 0 to 1 000 000 000:\n");
    while (1) 
    {
        if (fgets(str_UN, sizeof(str_UN), stdin) != NULL) 
        {
            // Убираем символ новой строки, если он присутствует
            str_UN[strcspn(str_UN, "\n")] = 0;

            // Проверяем, что каждая часть строки — это цифра
            length_str_UN = (int)strlen(str_UN);
            isValid = 1;
            for (i = 0; i < length_str_UN; i++)
            {
                if (!isdigit(str_UN[i])) 
                {
                    isValid = 0;
                    printf("Error! Incorrect value!\n");
                    break;
                }
            }

            if (isValid == 1) 
            {
                // Преобразуем строку в число для того, чтобы проверить подходит ли оно под диапазон
                UN = (int)strtoull(str_UN, NULL, 10);

                if (UN < 0 || UN > 1000000000) 
                {
                    printf("Error! Incorrect value!\n");
                    break;
                }
                else
                {
                    printf("Good job! You type correct argument!\n");
                    break;
                }
            } 
        }
        printf("Please type your number again:\n");
    }
    printf("Valid number entered: %d\n", UN);



    for (base = 2; base <= 36; ++base) 
    {
        printf("Base %d:\n", base);
        convert_to_base(UN, base, digits, &digit_count);
        print_histogram(digits, digit_count, base);
        printf("\n");
    }


    return 0;
}