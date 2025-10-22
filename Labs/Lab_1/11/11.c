#include <stdio.h>

int my_strcmp(char const *str1, char const *str2) 
{
    for(int i = 0; str1[i] != 0 || str2[i] != 0; i++)
     {
        if(str1[i] > str2[i])
        {
            return 1;
            break;
        }
        else if(str1[i] < str2[i])
        {
            return -1;
            break;
        }
     }   
     return 0;
}

int main()
{
    char str1[BUFSIZ], str2[BUFSIZ];
    printf("Please entry a two lines that you want to identify:\n");
    printf("Please entry the first line.\n");
    scanf("%s", str1);
    printf("Good. Now please entry the second line.\n");
    scanf("%s", str2);

    if (my_strcmp(str1, str2) == 0)
    {
        printf("Yes, your lines is identical.\n");
    }
    else
    {
        printf("No, your lines is not identical.\n");
    }
    return 0;
}