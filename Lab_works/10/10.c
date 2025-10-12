#include <stdio.h>
#include <string.h>


char my_strcat(char *str1, char const *str2) 
{
    int len1, len2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    for(int i = 0; i <= len2; i++)
    {
        str1[len1 + i] = str2[i]; 
    }
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