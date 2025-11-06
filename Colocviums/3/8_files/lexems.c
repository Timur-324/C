#include <stdio.h>
#include <ctype.h>
#include <string.h>

void extract_lexemes(const char *input) 
{
    int i = 0;
    int start = 0;
    int in_lexeme = 0;
    char lexeme[100]; // Буфер для хранения текущей лексемы

    while (input[i] != '\0') 
    {
        if (isalnum(input[i])) 
        { // Если символ является частью лексемы
            if (!in_lexeme) 
            {
                start = i; // Запоминаем начало лексемы
                in_lexeme = 1;
            }
        } 
        else // Если символ является разделителем
        { 
            if (in_lexeme) 
            {
                int length = i - start;
                strncpy(lexeme, &input[start], length);
                lexeme[length] = '\0'; // Добавляем завершающий нулевой символ
                printf("Lexeme: %s\n", lexeme);
                in_lexeme = 0;
            }
        }
        i++;
    }

    // Обработка последней лексемы, если строка не заканчивается разделителем
    if (in_lexeme) {
        int length = i - start;
        strncpy(lexeme, &input[start], length);
        lexeme[length] = '\0';
        printf("Lexeme: %s\n", lexeme);
    }
}

int main() 
{
    const char *input = "Hello, World! This is a test.";
    extract_lexemes(input);
    return 0;
}