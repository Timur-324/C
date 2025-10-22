#include <stdio.h>
int reverse(char *str)
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
        if(*first_symbol_of_str != *last_symbol_of_str) /*здесь я разименовал указатели, чтобы сравнивать значения*/
        {
            return 0;
            break;
        }
        first_symbol_of_str++;
        last_symbol_of_str--;
    }
    return 1;
}


int main()
{
    char str[BUFSIZ];
    int is_palenrdome = 0;
    printf("Hello, please enter a line that you want to check on the feature of palindrome.\n");
    scanf("%s", str);
    if (reverse(str) == 1)
    {
        printf("Yes, your line is palendrome\n");
    }
    else
    {
        printf("No, your line is not palendrome\n");
    }
    return 0;
}