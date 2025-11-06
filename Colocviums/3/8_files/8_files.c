// #include <stdio.h>
// #include <limits.h>

// int main()
// {
//     FILE *input_file; // FILE is typedef for struct _iobuf
//     FILE *output_file;

//     char const *file_path = "C:\\Users\\scarl\\Desktop\\pukipuki.txt";
    
//     input_file = fopen(file_path, "r");
//     if (input_file == NULL)
//     {
//         // File not opened!
//         // TODO: handle fopen retval
//         return -1;
//     }

//     // loop of reading file with EOF handling
//     while (!feof(input_file))
//     {
//         // read character from file stream,
//         char readChar = fgetc(input_file);
        
//         // then handle it
//         putc(readChar, stdout);
//         // printf("%c", readChar);
//     }
    
//     // open file variable with opening validation
//     // if (!(input_file = fopen("path", "mode"))) { // File not opened! }
    
//     // TODO: read about this functions
//     // fgetc, fscanf, fprintf, fputs
//     // fread, fwrite, open, close
//     // rewind

//     // close previously
//     fclose(input_file);

//     input_file = fopen(file_path, "r");
//     if (input_file == ((void *)0))
//     {
//         return -2;
//     }

//     // loop of reading file without EOF handling
//     char c;
//     while ((c = fgetc(input_file)) != EOF)
//     {
//         // TODO: handle read character
//     }

//     fclose(input_file);

// 	return 0;
// }



#include <stdio.h>

int main() 
{
    // Пример 1: Чтение файла посимвольно с обработкой конца файла
    FILE *file = fopen("example.txt", "r");
    
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
    // Такая обработка на открытие обязательна, но я её пока опустил 
    //if (!file) {
    //    printf("Error opening file\n");
    //    return 1;
    //}

    printf("Reading file character by character:\n");
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);



    // Пример 2: Чтение файла построчно без явной обработки конца файла
    printf("\n\nReading file line by line:\n");
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }
    fclose(file);



    // Пример 3: Запись в файл посимвольно
    file = fopen("example.txt", "w");
    const char *text = "Hello, World!";
    for (int i = 0; text[i] != '\0'; i++) {
        fputc(text[i], file);
    }
    fclose(file);



    // Пример 4: Запись строки в файл
    file = fopen("example.txt", "a");
    if (!file) {
        printf("Error opening file for appending\n");
        return 1;
    }
    fputs("\nAppending this line to the file.\n", file);
    fclose(file);



    // Пример 5: Чтение и запись бинарных данных
    file = fopen("data.bin", "wb");
    int data[] = {1, 2, 3, 4, 5};
    fwrite(data, sizeof(int), 5, file);
    fclose(file);




    file = fopen("data.bin", "rb");
    if (!file) {
        printf("Error opening file for binary reading\n");
        return 1;
    }
    printf("\n\nReading binary data:\n");
    int bufferInt[5];
    fread(bufferInt, sizeof(int), 5, file);
    for (int i = 0; i < 5; i++) {
        printf("%d ", bufferInt[i]);
    }
    printf("\n");
    fclose(file);


//    Основные функции для работы с файлами в C
//
//#### Открытие и закрытие файлов
//
//- fopen(const char filename, const char mode)  
//
//  Открывает файл с указанным именем и режимом.
//
//  - Пример: fopen("example.txt", "r");
//
//- fclose(FILE *stream)  
//
//  Закрывает файл.
//
//  - Пример: fclose(file);
//



//#### Чтение из файла
//
//- fgetc(FILE *stream)  
//
//  Читает один символ из файла.
//
//  - Пример: int ch = fgetc(file);
//
//- fgets(char str, int n, FILE stream)  
//
//  Читает строку из файла размером до n-1 символов.
//
//  - Пример: fgets(buffer, sizeof(buffer), file);
//
//- fread(void ptr, size_t size, size_t count, FILE stream)  
//
//  Читает бинарные данные из файла.
//
//  - Пример: fread(buffer, sizeof(int), 5, file);
//



//#### Запись в файл
//
//- fputc(int char, FILE *stream)  
//
//  Записывает один символ в файл.
//
//  - Пример: fputc('A', file);
//
//- fputs(const char str, FILE stream)  
//
//  Записывает строку в файл.
//
//  - Пример: fputs("Hello, World!\n", file);
//
//- fwrite(const void ptr, size_t size, size_t count, FILE stream)  
//
//  Записывает бинарные данные в файл.
//
//  - Пример: fwrite(data, sizeof(int), 5, file);
//



//#### Проверка состояния файла
//
//- feof(FILE *stream)  
//
//  Проверяет, достигнут ли конец файла.
//
//  - Пример: if (feof(file)) { / end of file reached / }
//
//- ferror(FILE *stream)  
//
//  Проверяет наличие ошибки в потоке.
//
//  - Пример: if (ferror(file)) { / handle error / }
//


//#### Перемещение по файлу
//
//- fseek(FILE *stream, long offset, int whence)  
//
//  Перемещает указатель на определенную позицию в файле.
//
//  - Пример: fseek(file, 0, SEEK_SET);
//
//- ftell(FILE *stream)  
//
//  Возвращает текущую позицию указателя в файле.
//
//  - Пример: long pos = ftell(file);
//
//- rewind(FILE *stream)  
//
//  Возвращает указатель файла на начало.
//
//  - Пример: rewind(file);
    return 0;
}