#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define MAXSIZE 4
int queue[MAXSIZE];
int front = -1;
int rear = -1;
int isFull() {
    return (rear == MAXSIZE - 1);
}
int isEmpty() {
    return (front == -1);
}
void enqueue(int item) {
    if (isFull()) {
        puts("Queue is Full");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = item;
    }
}
int dequeue() {
    int item;
    if (isEmpty()) {
        puts("Queue is empty");
        return INT_MIN;
    } else {
        item = queue[front];
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
        return item;
    }
}
void display() {
    if (isEmpty()) {
        puts("Queue is Empty");
    } else {
        puts("The elements are:");
        for (int i = front; i <= rear; i++) {
            printf(" %3d", queue[i]);
        }
        printf("\n");
    }
}
int main() {
    int choice, item;
    printf("\t LINEAR QUEUE MENU\n");
    puts("1. Enqueue");
    puts("2. Dequeue");
    puts("3. Display");
    puts("4. Exit");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (isFull()) {
                    puts("Queue is Full. Cannot enqueue.");
                    break;
                }
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                if (item != INT_MIN)
                    printf("Deleted element from front is %d\n", item);
                break;
            case 3:
                display();
                break;
            case 4:
                puts("Exiting...");
                exit(0);
            default:
                puts("Invalid choice");
        }
    }
    return 0;
}