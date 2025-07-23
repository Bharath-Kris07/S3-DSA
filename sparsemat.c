#include <stdio.h>

#define MAX 100

struct term {
    int row, col, val;
};
void printFullMatrix(struct term mat[], int isTransposed) {
    int full[MAX][MAX] = {0};
    int i, r = mat[0].row, c = mat[0].col, nz = mat[0].val;

    for (i = 1; i <= nz; i++) {
        full[mat[i].row][mat[i].col] = mat[i].val;
    }

    for (i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", full[i][j]);
        }
        printf("\n");
    }
}

// Transpose function (returns number of non-zero elements)
int transpose(struct term src[], struct term dest[]) {
    int i, j, k = 1;
    int rows = src[0].row;
    int cols = src[0].col;
    int nz = src[0].val;

    dest[0].row = cols;
    dest[0].col = rows;
    dest[0].val = nz;

    for (i = 0; i < cols; i++) {
        for (j = 1; j <= nz; j++) {
            if (src[j].col == i) {
                dest[k].row = src[j].col;
                dest[k].col = src[j].row;
                dest[k].val = src[j].val;
                k++;
            }
        }
    }
    return nz;
}

int main() {
    struct term A[MAX], B[MAX], C[2 * MAX], T[MAX];
    int m, n, i, j, k = 1;

    printf("Enter number of rows and columns of the matrices: ");
    scanf("%d%d", &m, &n);

    int numA, numB;
    printf("Enter number of non-zero elements in Matrix A: ");
    scanf("%d", &numA);
    printf("Enter elements of A (row col val):\n");
    A[0].row = m;
    A[0].col = n;
    A[0].val = numA;
    for (i = 1; i <= numA; i++) {
        scanf("%d%d%d", &A[i].row, &A[i].col, &A[i].val);
    }

    printf("Enter number of non-zero elements in Matrix B: ");
    scanf("%d", &numB);
    printf("Enter elements of B (row col val):\n");
    B[0].row = m;
    B[0].col = n;
    B[0].val = numB;
    for (i = 1; i <= numB; i++) {
        scanf("%d%d%d", &B[i].row, &B[i].col, &B[i].val);
    }

    // Ask user which matrix to transpose
    char choice;
    printf("Which matrix do you want to transpose? (A/B): ");
    scanf(" %c", &choice);

    if (choice == 'A' || choice == 'a') {
        transpose(A, T);
        printf("\nTranspose of Matrix A:\n");
    } else if (choice == 'B' || choice == 'b') {
        transpose(B, T);
        printf("\nTranspose of Matrix B:\n");
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    for (i = 1; i <= T[0].val; i++) {
        printf("%d %d %d\n", T[i].row, T[i].col, T[i].val);
    }

    // Sum of matrices A and B into C
    i = j = k = 1;
    C[0].row = m;
    C[0].col = n;
    while (i <= A[0].val && j <= B[0].val) {
        if (A[i].row < B[j].row || 
            (A[i].row == B[j].row && A[i].col < B[j].col)) {
            C[k++] = A[i++];
        } else if (B[j].row < A[i].row || 
                   (A[i].row == B[j].row && B[j].col < A[i].col)) {
            C[k++] = B[j++];
        } else {
            int sum = A[i].val + B[j].val;
            if (sum != 0) {
                C[k].row = A[i].row;
                C[k].col = A[i].col;
                C[k].val = sum;
                k++;
            }
            i++; j++;
        }
    }
    while (i <= A[0].val) C[k++] = A[i++];
    while (j <= B[0].val) C[k++] = B[j++];
    C[0].val = k - 1;

    // Print Sum
    printf("\nSum of Matrix A and B:\n");
    for (i = 1; i <= C[0].val; i++) {
        printf("%d %d %d\n", C[i].row, C[i].col, C[i].val);
    }

    printFullMatrix(C, 0);
    return 0;
}