#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        return;
    }

    new_node->data = data;
    new_node->next = top;
    top = new_node;
}

int pop() {
    if (top == NULL) {
        return -1;
    }

    struct node *temp = top;
    int popped_data = temp->data;
    top = top->next;
    free(temp);
    return popped_data;
}

int main() {
    struct node *top = NULL; 
    
    for(int i = 0; i < 5; i++) {
        float k = 0;
        scanf("%f", &k);
        push(k);
    }

    printf("Print stack\n");

    for(int i = 0; i < 5; i++) {
        printf("%d\n", pop());
    }

    return 0;
}

