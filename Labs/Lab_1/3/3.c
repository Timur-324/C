#include <stdio.h>
// собственная функция power 
int power(int on_what_power_we_need_to_raise_num, int counter_of_power) // функция принимает два числа в внутри скобочек() + добавил к каждому параметру внутри () int, потому что в С обязательно нужно добавить тип каждому аргументу функции
{
    int result_of_power = 1, cycle_counter;
    for (int cycle_counter = 0; cycle_counter < counter_of_power; cycle_counter++) 
    {
        result_of_power *= on_what_power_we_need_to_raise_num;
    }
    return result_of_power;
}


int main()
{
    printf("Here is your table with powers form 1-10 for 1-6.");
    int num = 1, counter_of_power, on_what_power_we_need_to_raise_num;
    for(num; num <= 6; num++)
    {
        printf("\nNumber %d:\n", num);
        if(num == 1)
        {
            printf("For one all results of power is one.\n");
        }
        else
        {
            for(counter_of_power = 1; counter_of_power <= 10; counter_of_power++)
            {
                printf("%d^%d = %d\n", num, counter_of_power, power(num, counter_of_power));
            }
        }
    }
    return 0;
}
