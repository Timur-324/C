#include <stdio.h>
void reverse(char *str) /*испоьлзую void  тк мне не нужно ничего возвращять. 
Мне нужно уже внутри функции поменять строку верх тормашками и вывести на консоль.
указатель на  str - тоесть ввожу адрес первого символа строки*/
{
    char *first_symbol_of_str, *last_symbol_of_str, temporal_storage;
    first_symbol_of_str = str;
    last_symbol_of_str = str;
    while (*last_symbol_of_str != 0)
    {
        last_symbol_of_str++;
    }
    last_symbol_of_str--;
    

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