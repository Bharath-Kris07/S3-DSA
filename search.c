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
int main(){
    int n,key;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int A[n];
    printf("Enter %d sorted elements: ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    printf("Enter element to search: ");
    scanf("%d",&key);
    binary_search(A,n,key);
    return 0;
}