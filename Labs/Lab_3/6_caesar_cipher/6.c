#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


int is_all_uppercase(const char *str) 
{
    if(str == NULL){return -1;}
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (!isupper(str[i])) 
        {
            return -2;
        }
    }
    return 0;
}

int caesar_cipher(char *str, int shift) 
{
    if(str == NULL){return -1;}
    if(shift < 0){return -2;}
    shift %= 26;
    for (int i = 0; str[i] != '\0'; i++) 
    {
        str[i] = 'A' + (str[i] - 'A' + shift) % 26;
    }
    return 0;
}

int main(int argc, char *argv[]) 
{
    srand((unsigned int)time(NULL));
    char *input_str;
    int shift;
    if (argc != 2) 
    {
        printf("Error! Not enough arguments!\n");
        return -1;
    }

    input_str = argv[1];
    shift = rand() % 1000 + 1;

    switch(is_all_uppercase(input_str))
    {
        case -1:
            printf("You put NULL in func!\n");
            return-2;
        case -2:
            printf("Error! Input string must contain only uppercase letters!\n");
            return -3;
    }

    switch(caesar_cipher(input_str, shift))
    {
        case -1:
            printf("You put NULL in function!\n");
            return -4;
        case -2:
            printf("The number in put in function is lower than 0!\n");
            return -5;
    }
    printf("Encrypted string: %s\n", input_str);

    return 0;
}