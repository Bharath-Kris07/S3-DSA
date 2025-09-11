#include <stdio.h>
void binary_search(int A[],int n,int key){
    int mid,low=0,high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(A[mid]==key){
            printf("Element %d found at index %d\n",key,mid);
            return;
        }
        if(A[mid]<key){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    printf("Element %d not found\n",key);
}