#include <stdio.h>
#include <stdlib.h>
void swap(int *x,int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void bubble_sort(int A[],int n){
    for(int pass=1;pass<=n-1;pass++){
        for(int i=0;i<n-pass-1;i++){
            if(A[i]>A[i+1]){
                swap(&A[i],&A[i+1]);
            }
        }
    }
}
void selection_sort(int A[],int n){
    for(int i=0;i<n-1;i++){
        int mindex=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[mindex]){
                mindex=j;
            }
        }
        if(mindex!=i)
        swap(&A[i],&A[mindex]);
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
int partition(int A[],int low,int high){
    int pivot=A[high];
    int i=low-1;
    int j=low;
    for(;j<high;j++){
        if(A[j]<=pivot){
            i++;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[high]);
    return i+1;
}
void quick_sort(int A[],int low,int high){
    if(low<high){
        int pi=partition(A,low,high);
        quick_sort(A,low,pi-1);
        quick_sort(A,pi+1,high);
    }
}
void merge(int A[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=A[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=A[m+1+j];
    }
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
        k++;
    }
     while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(int A[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        merge_sort(A,l,m);
        merge_sort(A,m+1,r);
        merge(A,l,m,r);
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
    printf("Choose sorting method:\n1. Bubble Sort\n2. Insertion Sort\n 3. Quick Sort\n 4. Selection Sort\n 5. Merge Sort\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            bubble_sort(A,n);
            break;
        case 2:
            insertion_sort(A,n);
            break;
        case 3:
            quick_sort(A,0,n-1);
            break;
        case 4:
            selection_sort(A,n);
            break;
        case 5:
            merge_sort(A,0,n-1);
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