#include <stdio.h>
int main() {
    int value1, value2, value3;
    printf("print 3 integral numbers:");
    if (scanf("%d%d%d", &value1, &value2, &value3)!= 3){
    }
    
    // a)
    if (value1 = value2 + value3 || 
        value2 = value3 + value1 ||
        value3 = value1 + value2)
    
    // б)
    // &&(одномерменно)
    // строиться условие на основе теоремы 
    if (value1 > 0 && value2 > 0 && value3 > 0 &&
        value1 + value2 > value3 &&
        value1 - value2 < value3 &&
        value2 - value1 < value3 &&
        value3 + value2 > value1 &&
        value3 - value2 < value1 &&
        value2 - value3 < value1 &&
        value1 + value3 > value2 &&
        value1 - value3 < value2 &&
        value3 - value1 < value2)
    
    // в)
    // чтобы проверить как у нас проверяться вот это условие (n & (n - 1))
    // у нас получаеться вот примерно это (00100000 00000000  & 00011111 11111111)  
    int n = value1 + value2 + value3;
    int is_power_of_two = (n & (n - 1)) == 0 && n > 0;
    printf("Is power of 2: %d", is_power_of_two);
    return 0;
}