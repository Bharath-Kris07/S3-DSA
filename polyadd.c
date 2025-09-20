#include <stdio.h>
#include <stdlib.h>
struct poly{
    float coeff;
    int exp;
};
int main(){
    struct poly *A,*B,*C;
    int m,n,i,j,k;
    puts("enter the number of terms in the first polynomial");
    scanf("%d",&m);
    puts("enter the number of terms in the second polynomial");
    scanf("%d",&n); 
    A=(struct poly *)malloc(m*sizeof(struct poly));
    B=(struct poly *)malloc(n*sizeof(struct poly));
    C=(struct poly *)malloc((m+n)*sizeof(struct poly));
    if(A==NULL||B==NULL||C==NULL){
        puts("memory allocation failed");
        return 1;
    }
    puts("enter the coefficients and exponents of the first polynomial in decreasing order");
    for(i=0;i<m;i++){
        scanf("%f%d",&(A+i)->coeff,&(A+i)->exp);
    }
    puts("enter the coefficients and exponents of the second polynomial in decreasing order");
    for(i=0;i<n;i++){   
        scanf("%f%d",&(B+i)->coeff,&(B+i)->exp);
    }
    i=j=k=0;
    while(i<m && j<n){
        if((A+i)->exp==(B+j)->exp){
            (C+k)->coeff=(A+i)->coeff+(B+j)->coeff;
            (C+k)->exp=(A+i)->exp;
            i++;
            j++;
            k++;
        }
        else if((A+i)->exp>(B+j)->exp){
            (C+k)->coeff=(A+i)->coeff;
            (C+k)->exp=(A+i)->exp;
            i++;
            k++;
        }
        else if((A+i)->exp<(B+j)->exp){
            (C+k)->coeff=(B+j)->coeff;
            (C+k)->exp=(B+j)->exp;
            j++;
            k++;
        }
      }
      while(i<m){
        (C+k)->coeff=(A+i)->coeff;
        (C+k)->exp=(A+i)->exp;
        i++;
        k++;
      }
    while(j<n){
        (C+k)->coeff=(B+j)->coeff;
        (C+k)->exp=(B+j)->exp;
        j++;
        k++;
    }
    puts("the resultant polynomial is");
    for(i=0;i<k;i++){
        printf("%.1fx^%d",(C+i)->coeff,(C+i)->exp);
        if(i<k-1)
            putchar('+');
    }
    free(A);
    free(B);
    free(C);
    return 0;
}
