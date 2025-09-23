#include <stdio.h>
#include <stdbool.h>
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
node* insertBST(node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertBST(root->left, data);
    } else if (data > root->data) {
        root->right = insertBST(root->right, data);
    }
    return root;
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
node* deleteNode(node* root, int key) {
    if (root == NULL) {
        puts("Node not found or tree is empty");
        return NULL;
    }
    node* parent = NULL;
    node* curr = root;
    while (curr != NULL && curr->data != key) {
        parent = curr;
        if (key < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    if (curr == NULL) {
        puts("Node not found");
        return root;
    }
    if (curr->left == NULL && curr->right == NULL) {
        if (curr == root) {
            free(root);
            return NULL;
        }
        if (parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
        free(curr);
    }
    else if (curr->left && curr->right) {
        node* succParent = curr;
        node* succ = curr->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        curr->data = succ->data;
        if (succParent == curr) succParent->right = succ->right;
        else succParent->left = succ->right;
        free(succ);
    }
    else {
        node* child = (curr->left != NULL) ? curr->left : curr->right;
        if (curr == root) {
            free(root);
            return child;
        }
        if (parent->left == curr) parent->left = child;
        else parent->right = child;
        free(curr);
    }
    return root;
}
int main(){
    int choice, data;
    node* root = NULL;
    do {
        puts("\nEnter your choice:");
        puts("1. Insert into BST");
        puts("2. Preorder Traversal");
        puts("3. Inorder Traversal");
        puts("4. Postorder Traversal");
        puts("5. Delete a node");
        puts("6. Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                puts("Enter data to insert into BST:");
                scanf("%d",&data);
                root = insertBST(root, data);
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
                if(root == NULL){
                    puts("Tree is empty!");
                    break;
                }
                puts("Enter the node to be deleted");
                scanf("%d",&data);
                root = deleteNode(root,data);
                break;
            case 6:
                puts("Exiting...");
                break;
            default:
                puts("Invalid choice");
        }
    } while(choice!=6);
    return 0;
}