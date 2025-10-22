#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(int argc, char * argv[])
{
    char input_file_path[256], input_file_path_2[256]; /*массивы для хранения путей*/
    char output_file_path[256], output_file_path_2[256];
    printf("Hello! Please enter a adress to the file from were I need to reed numbers from 2 to 36 base of system:\n");
    fgets(input_file_path, sizeof(input_file_path), stdin);  /*читаем строку с путём на файл*/
    printf("Great! Now please enter the output file:\n");
    fgets(output_file_path, sizeof(output_file_path), stdin);


    /*открываю файл и читаю значения*/
    FILE *input_file;
    FILE *output_file;

    char ch, _pch = 0;
    char buffer[256];
    char *pb = buffer;

    char const * const filePath_2 = output_file_path_2;
    char const * const filePath = input_file_path_2;
    output_file = fopen(filePath_2, "w");
    input_file = fopen(filePath, "r");
    if (input_file == NULL)
    {
        printf("Error of opening input file!\n");
        return -1;
    }
    if(output_file == NULL)
    {
        printf("Error of opening output file!\n");
        return -2;
    }

    while (!(feof(input_file)))
    {
        ch = fgetc(input_file);
        if (isalnum(ch))
        {
            *pb ++= ch;
        }
        else if (isalnum(_pch))
        {
            *pb = 0;
            fprintf(output_file, "%s\n", buffer);  /*Записываем число в выходной файл*/
            pb = buffer;
        }
        _pch = ch;
    }
        

    fclose(input_file);
    fclose(output_file);
    return 0;

}