#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define maxsize 4
int front=-1,rear=-1,Q[maxsize];
int isFull(){
    return (front==(rear+1)%maxsize);
}
int isEmpty(){
    return (front==-1);
}
void EnqueueFront(int item){
    if(isFull()){
        puts("Queue is Full");
    }
    else if(isEmpty()){
        front=rear=0;
        Q[front]=item;
    }
    else{
            front=(front+maxsize-1)%maxsize;
            Q[front]=item;
    }
}
void EnqueueRear(int item){
    if(isFull()){
        puts("Queue is Full");
    }
    else if(isEmpty()){
        front=rear=0;
        Q[rear]=item;
    }
    else{
        rear=(rear+1)%maxsize;
        Q[rear]=item;
    }
}
int DequeueFront(){
    int item;
    if(isEmpty()){
        puts("Queue is empty");
        return INT_MIN;
    }
    else{
        item=Q[front];
        if(front==rear)
            front=rear=-1;
        else
        front=(front+1)%maxsize;
    }
    return item;
}
int DequeueRear(){
    int item;
    if(isEmpty()){
        puts("Queue is empty");
        return INT_MIN;
    }
    else{
        item=Q[rear];
        if(front==rear)
            front=rear=-1;
        else
        rear=(rear+maxsize-1)%maxsize;
    }
    return item;
}
void Display(){
    int i=front;
    if(isEmpty()){
        puts("Queue is Empty");
    }
    else{
        puts("The elements are");
    while(1){
        printf(" %3d",Q[i]);
        if(i==rear) break;
        i=(i+1)%maxsize;
    }
    printf("\n");
}}
int main(){
    int choice,item;
    printf("\t DEQUE MENU\n");
    puts("1. EnqueueFront");
    puts("2. EnqueueRear");
    puts("3. DequeueFront");
    puts("4. DequeueRear");
    puts("5. Display");
    puts("6. Exit");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
    case 1: 
        if(isFull()){
            puts("Queue is Full");
            break;
        }
        printf("Enter the element to insert: ");
        scanf("%d",&item);
        EnqueueFront(item);
        break;
    case 2: 
        if(isFull()){
            puts("Queue is Full");
            break;
        }
        printf("Enter the element to insert: ");
        scanf("%d",&item);
        EnqueueRear(item);
        break;
    case 3: 
        item = DequeueFront();
        if(item != INT_MIN) 
            printf("Deleted element from front is %d\n", item);
        break;
    case 4: 
        item=DequeueRear();
        if(item!=INT_MIN)
            printf("Deleted element from rear is %d\n",item);
        break;
    case 5: 
        Display();
        break;
    case 6: 
        puts("Exiting...");
        exit(0);
    default: 
        puts("Invalid choice");
        }
    }
}