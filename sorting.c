#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int A[],int n){
    for(int pass=1;pass<=n-1;pass++){
        for(int i=0;i<n-pass-1;i++){
            if(A[i]>A[i+1]){
                int temp=A[i+1];
                A[i+1]=A[i];
                A[i]=temp;
            }
        }
    }
}
void insertion_sort(int A[],int n){
    for(int i=1;i<n;i++){
        int key=A[i];
        int j=i-1;
        while(j>=0&&A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}
int main(){
    int *A,n,choice;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    A=(int*)malloc(n*sizeof(int));
    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printf("Choose sorting method:\n1. Bubble Sort\n2. Insertion Sort\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            bubble_sort(A,n);
            break;
        case 2:
            insertion_sort(A,n);
            break;
        default:
            printf("Invalid choice\n");
            free(A);
            return 1;
    }
    printf("Sorted elements: ");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    free(A);
    return 0;
}