#include <stdio.h>

#define MAX_ELEMENTS 100

typedef struct {
    int row;
    int col;
    int value;
} SparseMatrixElement;

void transpose(SparseMatrixElement mat[], int numElements, SparseMatrixElement matTransposed[]) {
    int k = 0;
    for (int i = 0; i < numElements; i++) {
        matTransposed[k].row = mat[i].col;
        matTransposed[k].col = mat[i].row;
        matTransposed[k].value = mat[i].value;
        k++;
    }
}

void display(SparseMatrixElement mat[], int numElements) {
    for (int i = 0; i < numElements; i++) {
        printf("(%d, %d) = %d\n", mat[i].row, mat[i].col, mat[i].value);
    }
}

int main() {
    SparseMatrixElement mat[MAX_ELEMENTS];
    SparseMatrixElement matTransposed[MAX_ELEMENTS];
    int numElements, row, col, value;

    printf("Enter number of non-zero elements: ");
    scanf("%d", &numElements);

    for (int i = 0; i < numElements; i++) {
        printf("Enter row, column, and value of non-zero element %d: ", i + 1);
        scanf("%d %d %d", &row, &col, &value);
        mat[i].row = row;
        mat[i].col = col;
        mat[i].value = value;
    }

    printf("\nOriginal Sparse Matrix:\n");
    display(mat, numElements);

    transpose(mat, numElements, matTransposed);

    printf("\nTransposed Sparse Matrix:\n");
    display(matTransposed, numElements);

    return 0;
}

