#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* left, *right;
} node;
typedef struct stack {
    node* A[100];
    int top;
} stack;
void initStack(stack* s){ s->top=-1; }
int isEmpty(stack* s){ return s->top==-1; }
void push(stack* s,node* n){
    if(s->top==99){
        puts("stack overflow");
        return;
    }
    s->A[++(s->top)]=n;
}
node* pop(stack* s){
    return isEmpty(s)?NULL:s->A[(s->top)--];
}
node* createNode(int data){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
node* search(node* root,int key){
    if(!root) return NULL;
    if(root->data==key) return root;
    if(key < root->data) return search(root->left,key);
    return search(root->right,key);
}
void insertNode(node* root,int parent,int data,int isLeft){
    node* parentNode=search(root,parent);
    if(parentNode==NULL){
        puts("Parent node not found");
        return;
    }
    if(isLeft){
        if(parentNode->left!=NULL){
            puts("Left child already exists");
            return;
        }
        parentNode->left=createNode(data);
    } else {
        if(parentNode->right!=NULL){
            puts("Right child already exists");
            return;
        }
        parentNode->right=createNode(data);
    }
}
void preorder(node* root){
    if(root==NULL){ puts("Tree is empty"); return; }
    stack s; initStack(&s);
    node* ptr=root;
    while(ptr!=NULL || !isEmpty(&s)){
        while(ptr!=NULL){
            printf("%d ", ptr->data);
            push(&s,ptr);
            ptr=ptr->left; 
        }
        if(!isEmpty(&s)){
            ptr=pop(&s);
            ptr=ptr->right;
        }
    }
    printf("\n");
}
void inorder(node* root){
    if(root==NULL){ puts("Tree is empty"); return; }
    stack s; initStack(&s);
    node* ptr=root;
    while(ptr!=NULL || !isEmpty(&s)){
        while(ptr!=NULL){
            push(&s,ptr);
            ptr=ptr->left; 
        }
        if(!isEmpty(&s)){
            ptr=pop(&s);
            printf("%d ", ptr->data);
            ptr=ptr->right;
        }
    }
    printf("\n");
}
void postorder(node* root){
    if(root==NULL){ puts("Tree is empty"); return; }
    stack s1,s2;
    initStack(&s1);
    initStack(&s2);
    push(&s1,root);
    while(!isEmpty(&s1)){
        node* temp=pop(&s1);
        push(&s2,temp);
        if(temp->left) push(&s1,temp->left);
        if(temp->right) push(&s1,temp->right);
    }
    while(!isEmpty(&s2)){
        node* temp=pop(&s2);
        printf("%d ", temp->data);    
    }
    printf("\n");
}
int main(){
    int choice,option,data,side;
    node* root=NULL;
    do {
        puts("\nEnter your choice:");
        puts("1. Create Tree");
        puts("2. Preorder Traversal");
        puts("3. Inorder Traversal");
        puts("4. Postorder Traversal");  
        puts("5. Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                puts("1. Root Node");
                puts("2. Insert Child");
                scanf("%d",&option);
                if(option==1){
                    puts("Enter data for root node:");
                    scanf("%d",&data);
                    root=createNode(data);
                } else if(option==2){
                    if(root==NULL){
                        puts("Create root node first!");
                        break;
                    }
                    puts("Enter the parent data:");
                    int parent; scanf("%d",&parent);
                    puts("Enter the data for child node:");
                    scanf("%d",&data);
                    puts("1. Left child  2. Right child");
                    scanf("%d",&side);
                    insertNode(root,parent,data, side==1);
                } else {
                    puts("Invalid option");
                }
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                puts("Exiting...");
                break;
            default:
                puts("Invalid choice");
        }
    } while(choice!=5);
    return 0;
}
