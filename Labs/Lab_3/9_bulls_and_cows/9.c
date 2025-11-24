#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>


int generateNumber(int *number) 
{
    srand((unsigned int)time(NULL));
    int currentDigit, previousDigit = -1;  
    int i, j;
    int isUnique;
    for (i = 0; i < 4; i++) 
    {
        do 
        {
            isUnique = 1;
            currentDigit = rand() % 10;
            for (j = 0; j < i; j++) 
            {
                if (number[j] == currentDigit) 
                {
                    isUnique = 0;
                    break;
                }
            }
        } 
        while (!isUnique);
        number[i] = currentDigit;
    }
    return 0;
}

int isValidInput(const char *input) 
{
    if (strlen(input) != 4){return -1;}
    for (int i = 0; i < 4; i++) 
    {
        if (!(isdigit(input[i]))) 
        {
            return -2;
        }
    }
    return 0;
}

int calculateBullsAndCows(const int *secret, const int *input, int *bulls, int *cows) 
{
    if( secret == NULL ||
        input == NULL ||
        bulls == NULL ||
        cows == NULL) 
    {return -1;}
    
    int i, j;
    *bulls = 0;
    *cows = 0;
    int secretUsed[4] = {0};
    int inputUsed[4] = {0};

    for (i = 0; i < 4; i++) 
    {
        if (input[i] == secret[i]) 
        {
            (*bulls)++;
            secretUsed[i] = 1;
            inputUsed[i] = 1;
        }
    }
    for (i = 0; i < 4; i++) 
    {
        if (!inputUsed[i]) 
        {
            for (j = 0; j < 4; j++) 
            {
                if (!secretUsed[j] && input[i] == secret[j]) 
                {
                    (*cows)++;
                    secretUsed[j] = 1;
                    break;
                }
            }
        }
    }
    return 0;
}

int main() 
{

    int SecretNumber[4] = {0};
    if(generateNumber(SecretNumber) == -1)
    {
        printf("You put NULL in generator function!\n");
        return -1;
    }


    char input[5];
    int int_input[4];
    int bulls = 0, cows = 0;
    int i;

    printf("Guess a number of 4 unique numbers ;)\n");

    while (bulls != 4) 
    {
        printf("Enter your number:\n");
        scanf("%s", input);

        switch(isValidInput(input)) 
        {
            case -1:
                printf("Your number is bigger or lower that four!\n");
                continue;
            case -2:
                printf("You can put only digits!\n");
                continue;
        }

        for (i = 0; i < 4; i++) 
        {
            int_input[i] = input[i] - '0';
        }

        if(calculateBullsAndCows(SecretNumber, int_input, &bulls, &cows) == -1)
        {
            return -2;
        }
        printf("%d bulls, %d cows\n", bulls, cows);
    }

    printf("Congratulations! You guessed the number!\n");
    return 0;
}
