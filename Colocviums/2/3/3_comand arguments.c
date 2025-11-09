#include <stdio.h>
#include <stdarg.h>





// int main(int argc, char* argv[]) 
// {
//     if(argc != 2) {
//     printf("Error, u need 2 arguments.");
//     return 1;
//     }

//     FILE *input;

//     if(!(input = fopen(argv[1], "w"))) 
//     {
//     return -1;
//     }

//     char c;

//     while (!(c == fgetc(input))) 
//     {

//     }

//     fclose(input);
//     return 0;
// }
//                   ^
//                   |
//                   |
//   тут мы интерпритируем аргумент командной строки как путь к файлу, с которым в дальнейшем можно работать 
//   открывать его, записывать туда что-то и т.д.






// int main(int argc, char *argv[]) 
// {
//     printf("Количество аргументов: %d\n", argc);

//     for (int i = 0; i < argc; i++) 
//     {
//         printf("Аргумент %d: %s\n", i, argv[i]);
//     }

//     return 0;
// }




// t324@t324-NMH-WDX9:~/Desktop/Project/C/Colocviums/2$ ls
//  1  '1_str functions.c'   2  '2 _dynamic memory.c'   2.pdf   3  '3_comand arguments.c'
// t324@t324-NMH-WDX9:~/Desktop/Project/C/Colocviums/2$ 3.exe banana apple cherry
// 3.exe: command not found
// t324@t324-NMH-WDX9:~/Desktop/Project/C/Colocviums/2$ ./3 banana
// Количество аргументов: 2
// Аргумент 0: ./3
// Аргумент 1: banana

//              ^
//              |
//              |
// // как запустить программу и туда что-то передать 









int main(
    int argc,
    char *argv[])


{
    // if (argc != 3)
    // {
    //     printf("Error! We need two adresses to files!\n");
    //     return 1;
    // }

    FILE *input_file, *output_file;
    char c;

    input_file = fopen(argv[1], "r");
    // output_file = fopen(argv[2], "r");

    if (input_file == NULL)
    {
        printf("Error! Input file does not opened!\n");
        return -1;
    }

    // if (output_file == NULL)
    // {
    //     printf("Output file does not opened!");
    //     fclose(output_file);
    //     return -2;
    // }

    while ((c = fgetc(input_file)) != EOF) //посимвольное считывание с файла с обработкой конца
    {
        printf("%c\n", c);
    }


    return 0;
}