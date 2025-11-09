// strlen, strcmp, strcat, strcpy, strstr, strdup
#include <stdio.h>
#include <stdlib.h> //for malloc

size_t my_strlen(const char *str1) //какова длина строки
{
    size_t acc = 0;
    while (*str1 != 0)
    {
        acc++;
        str1++;
    }
    return acc;
}




int my_strcmp(char const *str1, char const *str2) //сравнение строк
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





char* my_strcat(char *str1, char const *str2) //соеденение двух строк
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
    return str1;
}






char* my_strcpy(char* dst, const char* str) //coping one string to buffer
{
    char* ptr = dst;
    while (*str != 0) {
        *ptr = *str;
        ptr++;
        str++;
    }
    *ptr = 0; 
    return dst;
}







// !!!!!!! need to understand
char *my_strstr(const char *str1, const char *str2) 
{
    if (!*str2) // если str2 пустая строка — вернуть str1
        return (char *)str1;

    for (const char *h = str1; *h; h++) 
    {
        const char *h_ptr = h;
        const char *n_ptr = str2;

        while (*h_ptr && *n_ptr && *h_ptr == *n_ptr) 
        {
            h_ptr++;
            n_ptr++;
        }

        if (!*n_ptr) // дошли до конца str2 — нашли совпадение
            return (char *)h;
    }

    return NULL; // не нашли
}







// strdup - создание копии строки в динамической памяти
char *my_strdup(const char *str)
{
    if (str == NULL)
        return NULL; // стандартное поведение при некорректном указателе

    int len_str;
    len_str = my_strlen(str);
    char *dup = malloc(len_str + 1);    // выделяем память под копию + /0

    if (dup == NULL)
        return NULL; // если malloc не смог выделить память

    my_strcpy(dup, str); // копируем все символы, включая '\0'
    return dup;
}








int main()
{
    char str1[BUFSIZ], str2[BUFSIZ], *msc, *mscpy, *mstr, *msdup, dst[BUFSIZ];
    int l_str1, l_str2;
    printf("Please enter a str1:\n");
    scanf("%s", str1);
    printf("Please enter a str2:\n");
    scanf("%s", str2); 


    //strlen
    l_str1 = my_strlen(str1);
    l_str2 = my_strlen(str2);
    printf("Here is a strlen for str1: %d\n", l_str1);
    printf("Here is a strlen for str2: %d\n", l_str2);


    
    //strcmp with ternator operator
    printf("string are %s\n", my_strcmp(str1, str2) == 0 ? "equal" : "not equal");



    //strcat
    msc = my_strcat(str1, str2);
    printf("%s\n", msc);


    //srtcpy
    mscpy = my_strcpy(dst, str1);
    printf("%s\n",mscpy);


    //strstr
    mstr = my_strstr(str1, str2);
    printf("%s\n", mstr);


    //strdup
    msdup = my_strdup(str1);
    printf("%s\n", msdup);
    free(msdup);

}