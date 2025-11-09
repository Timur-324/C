#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * good_concat(
    size_t count,
    ...)
{
    char *result;
    size_t total_length = 0;
    size_t i;
    const char *str;

    //cheking on having some args
    if (count == 0)
    {
        printf("No arguments!\n");
        return strdup("")
    }

    //counting total length for malloc 
    va_list args;
    va_start(args, count);
    for (i = 0; i < count; ++i)
    {
        str = va_arg(args, const char*);
        total_length += strlen(str);
    }
    va_end(args);


    //allocating memory
    result = (char*)malloc(total_length + 1);
    if (result == NULL)
    {
        printf("Can not allocated memory with malloc!");
        return NULL;
    }

     
    //coping strings
    va_start(args, count);
    result[0] = '\0'; //doing empty string for strcat
    for (i = 0; i < count; ++i)
    {
        str = va_arg(args, const char*);
        strcat(result, str);
    }

    va_end(args);
    return result;
}



int main(
    int argc,
    char *argv[])
{
    char* concatenated_strings = good_concat(4, "AbC", "123", "!@#", "Hello!");
    switch ((size_t)concatenated_strings)
    {
        case 0:
            printf("Memory allocation error!");
            break;
        default:
            printf("Good concat result == \"%s\"\n", concatenated_strings);
            free(concatenated_strings);
            break;
    }
}