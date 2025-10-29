#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    if (argc != 5) {
        puts("Correct usage: ./filename rowsA colsA rowsB colsB");
        return 1;
    }
    int m1, n1, m2, n2, i, j, k,**A, **B, **C;
    m1 = atoi(argv[1]);
    n1 = atoi(argv[2]);
    m2 = atoi(argv[3]);
    n2 = atoi(argv[4]);
    if (n1 != m2) {
        puts("Matrix multiplication not possible (colsA must equal rowsB)");
        return 1;
    }
    A = malloc(m1 * sizeof(int *));
    B = malloc(m2 * sizeof(int *));
    C = malloc(m1 * sizeof(int *));
    for (i = 0; i < m1; i++) A[i] = malloc(n1 * sizeof(int));
    for (i = 0; i < m2; i++) B[i] = malloc(n2 * sizeof(int));
    for (i = 0; i < m1; i++) C[i] = malloc(n2 * sizeof(int));
    if (A == NULL || B == NULL || C == NULL) {
        puts("Memory allocation failed");
        return 1;
    }
    puts("Enter elements of Matrix A:");
    for (i = 0; i < m1; i++)
        for (j = 0; j < n1; j++)
            scanf("%d", &A[i][j]);
    puts("Enter elements of Matrix B:");
    for (i = 0; i < m2; i++)
        for (j = 0; j < n2; j++)
            scanf("%d", &B[i][j]);
    for (i = 0; i < m1; i++)
        for (j = 0; j < n2; j++) {
            C[i][j] = 0;
            for (k = 0; k < n1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    puts("Resultant Matrix C:");
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++)
            printf("%d ", C[i][j]);
        putchar('\n');
    }
    for (i = 0; i < m1; i++) free(A[i]);
    for (i = 0; i < m2; i++) free(B[i]);
    for (i = 0; i < m1; i++) free(C[i]);
    free(A); free(B); free(C);
    return 0;
}