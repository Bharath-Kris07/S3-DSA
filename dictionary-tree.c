#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char word[50],meaning[200];
    struct node* left,*right;
}node;
node* createNode(char* word,char* meaning){
    node* newnode=(node*)(malloc(sizeof(node)));
    strcpy(newnode->word,word);
    strcpy(newnode->meaning,meaning);
    newnode->left=newnode->right=NULL;
    return newnode;
}
node* insertNode(node* root,char* word,char* meaning){
    if(!root) return createNode(word,meaning);
    node* ptr=root;
    if(strcmp(word,ptr->word)>0){
        ptr->right=insertNode(ptr->right,word,meaning);
    }
    else if(strcmp(word,ptr->word)<0){
        ptr->left=insertNode(ptr->left,word,meaning);
    }
    else{
        puts("Word already exists in dictionary");
    }
    return root;
}
void searchNode(node* root,char* word){
    if(!root){
        puts("word not found in dictionary");
        return;
    }
    else{
        node* ptr=root;
        if(strcmp(word,ptr->word)==0){
            printf("%s\t: %s\n",ptr->word,ptr->meaning);
            return;
        }
        else if(strcmp(word,ptr->word)>0){
            searchNode(ptr->right,word);
        }
        else{
            searchNode(ptr->left,word);
        }
    }
}
void inorder(node* root){
   if(!root)
        return;
    inorder(root->left);
    printf("%s\t: %s\n",root->word,root->meaning);
    inorder(root->right);
   }
int main(){
    node* root=NULL;
    int choice;
    char word[50],meaning[200];
    do{
        puts("\nEnter your choice:");
        puts("1. Insert Word");
        puts("2. Search Word");
        puts("3. Display Dictionary");
        puts("4. Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                puts("Enter the word to insert:");
                scanf("%s",word);
                puts("Enter its meaning:");
                getchar();
                fgets(meaning,200,stdin);
                meaning[strcspn(meaning, "\n")] = 0; 
                root=insertNode(root,word,meaning);
                break;
            case 2:
                puts("Enter the word to search:");
                scanf("%s",word);
                searchNode(root,word);
                break;
            case 3:
                if(!root){
                    puts("Dictionary is empty");
                }
                else{
                    puts("The words in the dictionary are:");
                    inorder(root);
                }
                break;
            case 4:
                puts("Exiting...");
                break;
            default:
                puts("Invalid choice");
        }
    }while(choice!=4);
    return 0;
}