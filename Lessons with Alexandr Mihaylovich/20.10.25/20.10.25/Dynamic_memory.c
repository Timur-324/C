/*
Задача: под неизвестное количество строк размером BUFSIZ
выделить определённое количество памяти(чтобы туда записать строки)
и после вывести эти строки на экран.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ** strs = NULL;
    int count = 0;
    char buf[BUFSIZ];
    int i;

    printf("Program started! When you want to finish just type 'STOP'\n");
    while(1)
    {
        printf("Input string:\n");

        if(!fgets(buf, BUFSIZ, stdin)) {break;}

        buf[strcspn(buf, "\n")] = '\0';
        
        // gets(buf); -было в коде Александра Михайловича. Оказываеться gets уже устарела.

        if(!(strcmp(buf, "STOP")))
        {
            break;
        }

        strs = (char **)realloc(strs, ++count * sizeof(char *)); 
        if(strs == NULL)
        {
            printf("Can not allocate memory for realloc!");
            return -1;
        }

        strs[count - 1] = (char *)malloc((strlen(buf) + 1) * sizeof(char));
        if(strs[count - 1] == NULL)
        {
            printf("Can not allocate memory for malloc!");
            return -2;
        }

        strcpy(strs[count - 1], buf);
    }
    printf("Here is all your strings:\n");

    for (i = 0; i < count; i++)
    {
        printf("%s\n", strs[i]);
        free(strs[i]);
    }

    free(strs);

    return 0;
}