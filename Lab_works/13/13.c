#include <stdio.h>
#include <ctype.h>

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
    
    converter(str_num, sys_num, &result);
    printf("Your number will be %d in decimal system.\n", result);
    return 0;
} 