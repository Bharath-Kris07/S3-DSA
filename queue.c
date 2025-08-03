#include <stdio.h>
int Q[100], front = -1, rear = -1;
void enqueue(int item){
    if(rear==99){
        puts("queue is full");
    }
    else{
        if(front==-1){
            front=0;
        }
        Q[++rear]=item;
    }
}
int dequeue(){
    if(front==-1||front>rear){
        puts("queue is empty");
        return -1;
    }
    return Q[front++];
}
int peek(){
    if(front==-1 || front > rear){
        puts("queue is empty");
        return -1;
    }
    return Q[front];
}
int isEmpty(){
    return (front==-1||front>rear);
}
int isFull(){
    return (rear==99);
}
void displayQueue(){
    int i;
    if(isEmpty()){
        puts("queue is empty");
    }
    else{
        puts("the queue is");
        for(i=front;i<=rear;i++){
            printf("%3d",Q[i]);
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
                puts("enter the element to be inserted");
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2:
                item=dequeue();
                if(item==-1){
                    puts("dequeue operation failed");
                } else {
                    printf("Dequeued item: %d\n", item);
                }
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