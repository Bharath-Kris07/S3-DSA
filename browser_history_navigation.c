#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node{
    char url[100];
    struct node* prev,*next;
}node;
node* current=NULL;
void visit(char *site){
    printf("Visited %s\n",site);
    if(current==NULL){
        current=(node*)(malloc(sizeof(node)));
        strcpy(current->url,site);
        current->prev=current->next=NULL;
    }
    else{
        node* temp=current->next;
        while(temp!=NULL){
            node* toDelete=temp;
            temp=temp->next;
            free(toDelete);
        }
        current->next=NULL;
        node* newnode=(node*)(malloc(sizeof(node)));
        strcpy(newnode->url,site);
        newnode->prev=current;
        newnode->next=NULL;
        current->next=newnode;
        current=newnode;
    }
}
void back(){
    if(current==NULL||current->prev==NULL){
        puts("Reached the end of history");
    }else{
        current=current->prev;
        printf("Went back to %s\n",current->url);
    }
}
void forward(){
    if(current==NULL||current->next==NULL){
        puts("Reached the end of history");
    }else{
        current=current->next;
        printf("Went forward to %s\n",current->url);
    }
}
void viewHistory() {
    if (!current) {
        puts("No browsing history.");
        return;
    }
    node* temp = current;
    while (temp->prev) temp = temp->prev;
    puts("\nBrowsing History:");
    while (temp) {
        if (temp == current)
            printf("-> %s (current)\n", temp->url);
        else
            printf("   %s\n", temp->url);
        temp = temp->next;
    }
}
int main(){
    int choice;
    char site[100];
    do{
        printf("\tBrowser Menu\n");
        puts("1.New site");
        puts("2.Go back");
        puts("3.Go forward");
        puts("4.View History");
        puts("5.Exit");
        puts("enter your choice");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                puts("enter the url of the website");
                while (getchar() != '\n'); 
                fgets(site, sizeof(site), stdin);
                site[strcspn(site, "\n")] = '\0'; 
                visit(site);
                break;
            case 2:
                back();
                break;
            case 3:
                forward();
                break;
            case 4:
                viewHistory();
                break;
            case 5:
                puts("Exiting...");
                exit(0);
        }
    }while(choice!=5);
    return 0;
}