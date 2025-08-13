#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* link;
};
void traverse(struct node* head){
    struct node* ptr=head;
    if(head==NULL){
        printf("Linked list is empty");
    }
    else{
        puts("The elements are:");
        while(ptr!=NULL){
            printf(" %3d",ptr->data);
            ptr=ptr->link;
        }
    }
    printf("\n");
}
struct node* InsertBeginning(struct node* head,int x){
    struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
    if(newnode == NULL){
        printf("Memory Allocation failed\n");
    }
    else{
        newnode -> data = x;
        newnode -> link = head;
        head = newnode;
    }
    return head;
}
struct node* InsertEnd(struct node* head,int x){
    struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
    if(newnode==NULL){
        puts("Memory Allocation Failed");
        return head;
    }
    newnode -> data = x;
    newnode -> link = NULL;
    if(head==NULL){
        head=newnode;
        return head;
    }
    struct node* ptr=head;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=newnode;
    return head;
}
struct node* InsertPos(struct node* head,int x,int pos){
    struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
    if(newnode==NULL){
        puts("Memory Allocation failed");
        return head;
    }
    newnode -> data = x;
    newnode -> link = NULL;
    if(pos==1){
        newnode->link=head;
        head=newnode;
        return head;
    }
    struct node* ptr=head;
    int i;
    for(i=1;i<pos-1&&ptr!=NULL;i++)
        ptr=ptr->link;
    if(ptr==NULL){
        puts("position out of bounds");
        free(newnode);
        return head;
    }
    newnode->link=ptr->link;
    ptr->link=newnode;
    return head;
}
struct node* DeleteFirst(struct node* head){
    if(head==NULL){
        puts("Linked list is already empty");
        return head;
    }
    struct node* temp = head;
    head=head->link;
    free(temp);
    return head;
}
struct node* DeleteLast(struct node* head){
    if(head==NULL){
        puts("Linked list is already empty");
    }
    else if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node *curr = head, *prev = NULL;
        while(curr->link!=NULL){
            prev=curr;
            curr=curr->link;
        }       
        prev->link=NULL;
        free(curr);
    }
    return head;
}
struct node* DeletePos(struct node* head,int pos){
    if(head==NULL){
        puts("Linked list is already empty");
    }
    else if(pos==1){
        struct node* temp=head;
        head=head->link;
        free(temp);
    }
    else{
        struct node* curr = head, *prev = NULL;
        int i;
        for(i=1;i<pos && curr!=NULL;i++){
            prev=curr;
            curr=curr->link;
        }
        if(curr==NULL){
            puts("position out of bounds");
        }
        else{
            prev->link=curr->link;
            free(curr);
        }
    }
    return head;
}
int main(){
    struct node* head=NULL;
    int choice, x, pos;
    printf("\t Linked List Menu\n");
    puts("1.Insert at beginning");
    puts("2.Insert at end");
    puts("3.Insert at position");
    puts("4.Delete first");
    puts("5.Delete last");
    puts("6.Delete at position");
    puts("7.Traverse");
    puts("8.Exit");
    do{
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the element to be inserted: ");
                    scanf("%d",&x);
                    head=InsertBeginning(head,x);
                    break;
            case 2: printf("Enter the element to be inserted: ");
                    scanf("%d",&x);
                    head=InsertEnd(head,x);
                    break;
            case 3: printf("Enter the element to be inserted: ");
                    scanf("%d",&x);
                    printf("Enter the position: ");
                    scanf("%d",&pos);
                    head=InsertPos(head,x,pos);
                    break;
            case 4: head=DeleteFirst(head);
                    break;
            case 5: head=DeleteLast(head);
                    break;
            case 6: printf("Enter the position: ");
                    scanf("%d",&pos);
                    head=DeletePos(head,pos);
                    break;
            case 7: traverse(head);
                    break;
            case 8: puts("Exiting...");
                    break;
            default: puts("Invalid choice");
        }
    }while(choice!=8);
    return 0;
}