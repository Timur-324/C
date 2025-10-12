#include <stdio.h>
#include <string.h>
void reverse(char *str) /*испоьлзую void  тк мне не нужно ничего возвращять. 
Мне нужно уже внутри функции поменять строку верх тормашками и вывести на консоль.
указатель на  str - тоесть ввожу адрес первого символа строки*/
{
    char *first_symbol_of_str, *last_symbol_of_str, temporal_storage;
    int length_of_line;
    first_symbol_of_str = str;
    length_of_line = strlen(str); /*тут мы находим длину строки, чтобы переместить указатель на нужное место*/
    last_symbol_of_str = str + length_of_line - 1;
    /*тут я создал указатель на предпоследний символ строки,
    чтобы с дальнейшем в цикле можно было бежать до него. Смещаю на -1, так как мне не нужен NULL*/

    while(first_symbol_of_str < last_symbol_of_str)
    {
        temporal_storage = *first_symbol_of_str;
        *first_symbol_of_str = *last_symbol_of_str;
        *last_symbol_of_str = temporal_storage;
        first_symbol_of_str++;
        last_symbol_of_str--;
    }

}


int main()
{
    char str[BUFSIZ];
    printf("Hello, please enter a line that you want to reverse.\n");
    scanf("%s", str);
    reverse(str);
    printf("Here is your reversed line: %s\n", str);
    return 0;
}