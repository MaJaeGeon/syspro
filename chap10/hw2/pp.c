#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void addq(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (tail == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

int delete() {
    if (head == NULL) {
        return -1;
    }

    struct node *temp = head;
    int deleted_data = temp->data;

    head = head->next; 
    if (head == NULL) {
        tail = NULL;
    }

    free(temp);
    return deleted_data;
}

int main() {
    struct node *top = NULL; 
    
    for(int i = 0; i < 5; i++) {
        float k = 0;
        scanf("%f", &k);
        addq(k);
    }

    printf("Print queue\n");

    for(int i = 0; i < 5; i++) {
        printf("%d\n", delete());
    }

    return 0;
}

