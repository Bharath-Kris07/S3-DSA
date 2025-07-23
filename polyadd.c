#include <stdio.h>
#include <stdlib.h>
struct poly{
    float coeff;
    int exp;
};
int main(){
    struct poly *P,*Q, *R;
    int m,n,i,j,k;
    puts("enter the number of terms in the first polynomial");
    scanf("%d",&m);
    puts("enter the number of terms in the second polynomial");
    scanf("%d",&n); 
    P=(struct poly *)malloc(m*sizeof(struct poly));
    Q=(struct poly *)malloc(n*sizeof(struct poly));
    R=(struct poly *)malloc((m+n)*sizeof(struct poly));
    if(P==NULL||Q==NULL||R==NULL){
        puts("memory allocation failed");
        return 1;
    }
    puts("enter the coefficients and exponents of the first polynomial in decreasing order");
    for(i=0;i<m;i++){
        scanf("%f%d",&(P+i)->coeff,&(P+i)->exp);
    }
    puts("enter the coefficients and exponents of the second polynomial in decreasing order");
    for(i=0;i<n;i++){   
        scanf("%f%d",&(Q+i)->coeff,&(Q+i)->exp);
    }
    i=j=k=0;
    while(i<m && j<n){
        if((P+i)->exp==(Q+j)->exp){
            (R+k)->coeff=(P+i)->coeff+(Q+j)->coeff;
            (R+k)->exp=(P+i)->exp;
            i++;
            j++;
            k++;
        }
        else if((P+i)->exp>(Q+j)->exp){
            (R+k)->coeff=(P+i)->coeff;
            (R+k)->exp=(P+i)->exp;
            i++;
            k++;
        }
        else if((P+i)->exp<(Q+j)->exp){
            (R+k)->coeff=(Q+j)->coeff;
            (R+k)->exp=(Q+j)->exp;
            j++;
            k++;
        }
      }
      while(i<m){
        (R+k)->coeff=(P+i)->coeff;
        (R+k)->exp=(P+i)->exp;
        i++;
        k++;
      }
    while(j<n){
        (R+k)->coeff=(Q+j)->coeff;
        (R+k)->exp=(Q+j)->exp;
        j++;
        k++;
    }
    puts("the resultant polynomial is");
    for(i=0;i<k;i++){
        printf("%.1fx^%d",(R+i)->coeff,(R+i)->exp);
        if(i<k-1)
            putchar('+');
    }
    free(P);
    free(Q);
    free(R);
    return 0;
}