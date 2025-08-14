#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int coef,pow;
    struct node *link;
}node;
void traverse(node* head){
    node *temp=head;
    if(temp==NULL){
        puts("polynomial is empty");
        return;
    }
    while(temp!=NULL){
        printf("%d^%d",temp->coef,temp->pow);
        temp=temp->link;
        if(temp!=NULL && temp->coef > 0){
            printf(" + ");  
        }
    }
}
node* createNode(int coef,int pow){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->coef=coef;
    newnode->pow=pow;
    newnode->link=NULL;
    return newnode;
}
node* insertNode(node* head, int coef, int pow) {
    if (coef == 0) return head; 
    if (head == NULL) {
        return createNode(coef, pow);
    }
    node* temp = head;
    node* prev = NULL;
    while (temp != NULL && temp->pow > pow) {
        prev = temp;
        temp = temp->link;
    }
    if (temp != NULL && temp->pow == pow) {
        temp->coef += coef; 
        return head;
    }
    node* newnode = createNode(coef, pow);
    if (prev == NULL) { 
        newnode->link = head;
        return newnode;
    }
    prev->link = newnode;
    newnode->link = temp;
    return head;
}
node* addPoly(node* p1,node* p2){
    node* result=NULL;
    while(p1!=NULL && p2!=NULL){
        if(p1->pow > p2->pow){
            result=insertNode(result,p1->coef,p1->pow);
            p1=p1->link;
        }
        else if(p1->pow < p2->pow){
            result=insertNode(result,p2->coef,p2->pow);
            p2=p2->link;
        }
        else{
            result=insertNode(result,p1->coef+p2->coef,p1->pow);
            p1=p1->link;
            p2=p2->link;
        }
    }
    while(p1!=NULL){
        result=insertNode(result,p1->coef,p1->pow);
        p1=p1->link;
    }
    while(p2!=NULL){
        result=insertNode(result,p2->coef,p2->pow);
        p2=p2->link;
    }
    return result;
}
node* mulPoly(node* p1,node* p2){
    int coef,pow;
    node* result=NULL;
    while(p1!=NULL){
        node* temp=p2;
        while(temp!=NULL){
            coef=p1->coef*temp->coef;
            pow=p1->pow+temp->pow;
            result=insertNode(result,coef,pow);
            temp=temp->link;    
        }
        p1=p1->link;
    }
    return result;
}
int main(){
    node* p1=NULL,*p2=NULL,*result=NULL;
    int coef,pow,n1,n2,i,choice;
    puts("enter the number of terms in first polynomial");
    scanf("%d",&n1);
    puts("enter the number of terms in second polynomial");
    scanf("%d",&n2);
    puts("enter the first polynomial in decreasing order of power");
    for(i=0;i<n1;i++){
        printf("enter coefficient and power of term %d: ",i+1);
        scanf("%d %d",&coef,&pow);
        p1=insertNode(p1,coef,pow);
    }
    puts("enter the second polynomial in decreasing order of power");
    for(i=0;i<n2;i++){
        printf("enter coefficient and power of term %d: ",i+1);
        scanf("%d %d",&coef,&pow);
        p2=insertNode(p2,coef,pow);
    }
    while(1){
    puts("choose the operation to perform:");
    puts("1.Addition");
    puts("2.Multiplication");
    puts("3.Exit");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        result=addPoly(p1,p2);
        break;
        case 2:
        result=mulPoly(p1,p2);
        break;
        case 3:
        exit(0);
    }
    traverse(result);
}
    return 0;
}