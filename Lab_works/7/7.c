#include <stdio.h>
#include <math.h>
#include <ctype.h>
int is_prime(int const num)
{
    if(num == 1)
    {
        return 0;
    }
    else
    {
        for(int i = 2; i <= (int)sqrt(num); i++)
            {
                if(num % i == 0)
                {
                    return 0;
                    break;
                }
                else
                {
                    return 1;
                }
            }
        
    }
}

/*на вход поддаёться отдельный символ, если он равен любой из этих гласных, то возвращает один*/
int is_vowel(char const letter)
{
    if (letter == 'a' || letter == 'A'){return 1;}
    if (letter == 'e' || letter == 'E'){return 1;}
    if (letter == 'i' || letter == 'I'){return 1;}
    if (letter == 'o' || letter == 'O'){return 1;}
    if (letter == 'u' || letter == 'U'){return 1;}
    return 0;
}


// основная функция для изменения регистра
void transformate(char string[])
{
    int i = 0;
    for (int i = 0; string[i] != '\0'; i++) 
    {
        int posision = i + 1; /*начинаем отсчёт с единицы*/
        char letter = string[i];
        if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'))/*проверяю являеться ли символ буквой а не пробелом например*/
        {
            // Гласная на чётной позиции → сделать заглавной
            if (is_vowel(letter) && posision % 2 == 0) 
            {
                if (letter >= 'a' && letter <= 'z')
                    string[i] = toupper(letter); // поднять регистр
            }


            // Согласная на позиции с простым номером → сделать строчной
            else if (!is_vowel(letter) && is_prime(posision)) 
            {
                if (letter >= 'A' && letter <= 'Z')
                    string[i] = tolower(letter); // опустить регистр
            }
        }
    }
}




int main()
{
    char string[256];
    printf("Please enter a string that I need to convert:\n");
    fgets(string, 256, stdin/*standart inpuit - ввод с клавиатуры*/); /*fgets(куда записать, сколько читать, откуда читать)*/

    transformate(string);
    printf("%s\n", string);
    return 0;
} 