#include <stdio.h>
#include <string.h>
void converter(int num, int sys_num, char *result) 
{
    int r;
    char *p = result + BUFSIZ - 2; /*ставлю указатель в конец для того, чтобы получаемые числа записывать с конца*/
    // *p-- = 0; /*смещаю указатель с нуля на предпоследнюю ячейку*/
    while (num > 0) /*пока число не станет нулём будем делить его и записывать остаток от деления*/
    {
        r = num % sys_num; /*остаток от деления - цифра в новой системе*/
        *p-- = (r > 9) ? (r - 10 + 'A') : (r + '0');
        num /= sys_num;/*переходим к следующему числу, поэтому делю на основание*/
    }

    p++; // Перемещаемся к первой значимой цифре
    strcpy(result, p); // Копируем результат в начало строки


    //p++;/*указываю на начало строки - нового числа, которое получилось*/
    //for (char *s = result; *p; p++, s++)/*копипую результат - переворачиваю число, чтобы его можно было понять - из конца в начало*/
    //{
    //    *s = *p;
    //}
}

int main()
{
    int num, sys_num;
    char new_num[BUFSIZ];
    printf("Please enter a integer number:\n");
    scanf("%d", &num);
    printf("Good. Now please enter a system of numeration that you want your number to convert(2-36):\n");
    scanf("%d", &sys_num);    
    
    converter(num, sys_num, new_num);
    printf("Your number %d in system of numeration %d is %s\n", num, sys_num, new_num);

    return 0;
} 