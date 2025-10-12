 #include <stdio.h>
 #include <stdlib.h> // библиотека для srand
 #include <time.h> // библиотека для time
 // у меня стандарт массива BUFSIZ равно 8192


 int main() 
{
    int array_of_numbers[BUFSIZ], i;
    srand(time(NULL)); // инициализация генератора случайных чисел, scrand - это начальное значение генератора случайных чисел
    for(i = 0; i < BUFSIZ; i++)
    {
        array_of_numbers[i] = rand() % 20001 - 10000; //rand() даёт число от 0 до 20,000 и с помощью -10,000 мы сдвигаем диапазон рандомных значений на те котрые нам нужны [-10000; 10000]
    }


    int num_max = array_of_numbers[0], num_min = array_of_numbers[0], index_max = 0, index_min = 0;


    for(i = 0; i < BUFSIZ; i++) // прохожусь по массиву для того, чтобы найти индексы и значения макс и мин чисел
    {
        if(array_of_numbers[i] > num_max)
        {
            num_max = array_of_numbers[i];
            index_max = i;
        }
        if(array_of_numbers[i] < num_min)
        {
            num_min = array_of_numbers[i];
            index_min = i;
        }
    }
    printf("Here is the max element and his index: %d - %d\n", num_max, index_max);
    printf("Here is the min element and his index: %d - %d\n", num_min, index_min);
    return 0;
}