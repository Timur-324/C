#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_valid(char str_num[], int sys_num)
{
    char *p = str_num;
    int value;
    while (*p)
    {
        if (isdigit(*p))
            value = *p - '0';
        else if (isalpha(*p))
            value = toupper(*p) - 'A' + 10;
        else
            return 0;

        if (value >= sys_num)
            return 0;

        p++;
    }
    return 1;
}


void converter(char str_num[], int sys_num, int *result) 
{
    char *p = str_num;
    while (*p) 
    {
        *result = *result * sys_num + (isalpha(*p) ? *p - 'A' + 10 : *p - '0');
        p++;
    }
}

int main()
{
    char str_num[BUFSIZ];
    int sys_num, result = 0;
    printf("Please enter a number in system of numeration from 2 to 36:\n");
    scanf("%s", str_num);
    printf("Good. Now please enter a system of numeration of your number:\n");
    scanf("%d", &sys_num);    
    
    if (!is_valid(str_num, sys_num))
    {
        printf("Error: number '%s' cannot exist in base %d.\n", str_num, sys_num);
        return 1;
    }

    converter(str_num, sys_num, &result);
    printf("Your number will be %d in decimal system.\n", result);
    return 0;
} 