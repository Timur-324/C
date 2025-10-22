#include <stdio.h>
#include <string.h>


void my_strcat(char *str1, char const *str2) 
{
    int i = 0, j = 0;
    while (str1[i] != '\0')
    {
        i++;
    }

    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

int main()
{
    char str1[BUFSIZ], str2[BUFSIZ];
    printf("Please entry a two lines that you want to combine:\n");
    printf("Please entry the first line.\n");
    scanf("%s", str1);
    printf("Good. Now please entry the second line.\n");
    scanf("%s", str2);

    my_strcat(str1, str2);
    printf("Here is a result of combining two lines: %s\n", str1);
    return 0;
}