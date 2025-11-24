#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int CN, UN;
    int step = 0;

    srand((unsigned int)time(NULL));
    CN = rand() % 1000 + 1;
    
    printf("I imagine a number. Try to guess it ;)!\n");
    printf("A little tip: use a dichotomous number search.\n");
    while (1)
    {
        printf("Enter a number:\n");
        while(scanf("%d", &UN) != 1)
        {
            printf("Error! :[  Please type your number again:\n");
            while(getchar() != '\n');
            // scanf("%d", &UN);
        }
        if(UN > CN)
        {
            printf("GT\n");
            ++step;
        }
        else if(UN < CN)
        {
            printf("LT\n");
            ++step;
        }
        else if(UN == CN)
        {
            printf("EQ\n");
            ++step;
            break;
        }
    }

    printf("Huray! You guessed a number!\n");
    printf("You have done %d step to solve my riddle\n", step);
    return 0;
}