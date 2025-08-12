#include <stdio.h>
int Q[4], front = -1, rear = -1;
void enqueue(int item){
    if((rear+1)%4==front){
        puts("queue is full");
    }
    else{
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%4;
        Q[rear]=item;
    }
}
void dequeue() {
    if (front == -1)
        puts("queue is empty");
    else {
        printf("Dequeued item: %d\n", Q[front]);
        if (front == rear) {
            front = rear = -1; 
        } else {
            front = (front + 1) % 4;
        }
    }
}
int peek() {
    if (front == -1) {
        puts("queue is empty");
        return -1;
    }
    return Q[front];
}

int isEmpty() {
    return (front == -1);
}


int isFull(){
    return (rear+1)%4==front;
}
void displayQueue() {
    if (isEmpty()) {
        puts("queue is empty");
    } else {
        puts("The queue is:");
        int i = front;
        while (1) {
            printf("%3d", Q[i]);
            if (i == rear) break;
            i = (i + 1) % 4;
        }
        printf("\n");
    }
}
int main(){
    int choice,item;
    do{
        puts("enter your choice");
        puts("1. Enqueue");
        puts("2. Dequeue");
        puts("3. peek");
        puts("4. isEmpty");
        puts("5. isFull");
        puts("6. Display");
        puts("7. Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(isFull()){
                    puts("queue is full, cannot enqueue");
                    break;
                }
                puts("enter the element to be inserted");
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                item=peek();
                if(item==-1){
                    puts("peek operation failed");
                } else {
                    printf("Peeked item: %d\n", item);
                }
                break;
            case 4:
                item=isEmpty();
                if(item){
                    puts("queue is empty");
                }
                else{
                    puts("queue is not empty");
                }
                break;
            case 5:
                item=isFull();
                if(item){
                    puts("queue is full");
                }
                else{
                    puts("queue is not full");  
                }
                break;
            case 6:
                displayQueue();
                break;
            case 7:
                puts("exiting...");
                break;
            default:
                puts("invalid choice, please try again");
        }
    }while(choice!=7);
    return 0;
}