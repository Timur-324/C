#include <stdio.h>
#include <stdlib.h>

// Определение структуры узла
typedef struct Node
{
    int data;
    struct Node *pNext;
} Node;


// Функция для создания нового узла
struct Node* CreateNode(int data) 
{
    struct Node* newNode = (Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL){ return NULL;} 
    
    newNode->data = data;
    
    newNode->pNext = NULL;
    
    return newNode;
}



// Функция для добавления элемента в стек
int push(struct Node **pHead, int data)
{
    struct Node *newNode = CreateNode(data);
    
    if(newNode == NULL){ return -1;}
    
    newNode->pNext = *pHead;
    
    *pHead = newNode;
    
    return 0;
}



// Функция для извлечения элемента из стека
int pop(struct Node **pHead)
{
    if (*pHead == NULL)
    {
        return -1;
    }
    struct Node *nptr = (*pHead)->pNext;
    
    free(*pHead);
    
    *pHead = nptr;

    return 0;
}


// Функция для просмотра верхнего элемента стека
int peek(struct Node **pHead) 
{
    int data;
    if (pHead == NULL)
    {
        return -1;
    }
    data = (*pHead)->data;
    return data;
}




int main()
{
    struct Node *stack = NULL; // Инициализация стека

    push(&stack, 30);
    int res_of_peek = peek(&stack);
    printf("Peek result: %d\n", res_of_peek);
    

   

    // //Исрользовать, если нужно освободить весь стэк
    // while (pop(&stack) != -1)
    // {
    //     pop(&stack);
    // }

    return 0;
}