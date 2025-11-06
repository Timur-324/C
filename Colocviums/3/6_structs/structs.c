#include <stdio.h>
#include <stdlib.h>

// Определение структуры узла списка
typedef struct Node {
    int data;
    struct Node *next;
} Node;


// Функция для создания нового узла
Node* create_node(int data) 
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Добавление в начало
void push_front(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Добавление в конец
void push_back(Node **head, int data) {
    Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Удаление из начала
void pop_front(Node **head) {
    if (*head == NULL) return;
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Удаление из конца
void pop_back(Node **head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        Node *current = *head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
}

// Поиск элемента по индексу
Node* get_node_by_index(Node *head, int index) {
    int count = 0;
    Node *current = head;
    while (current != NULL) {
        if (count == index) {
            return current;
        }
        count++;
        current = current->next;
    }
    return NULL; // Индекс вне диапазона
}

// Поиск элемента по значению
Node* find_by_value(Node *head, int value) {
    Node *current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Значение не найдено
}

// Вставка узла после заданного узла
void insert_after(Node *prev_node, int data) {
    if (prev_node == NULL) return;
    Node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Удаление узла после заданного узла
void delete_after(Node *prev_node) {
    if (prev_node == NULL || prev_node->next == NULL) return;
    Node *temp = prev_node->next;
    prev_node->next = temp->next;
    free(temp);
}

// Функция для печати списка
void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL; // Начало списка

    // Пример использования
    push_front(&head, 3);
    push_front(&head, 2);
    push_front(&head, 1);
    print_list(head);

    push_back(&head, 4);
    push_back(&head, 5);
    print_list(head);

    pop_front(&head);
    print_list(head);

    pop_back(&head);
    print_list(head);

    Node *node = get_node_by_index(head, 1);
    if (node != NULL) {
        printf("Node at index 1: %d\n", node->data);
    }

    node = find_by_value(head, 3);
    if (node != NULL) {
        printf("Node with value 3: %d\n", node->data);
    }

    insert_after(head, 10);
    print_list(head);

    delete_after(head);
    print_list(head);

    return 0;
}