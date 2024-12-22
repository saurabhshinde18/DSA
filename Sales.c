#include <stdio.h>
#include <string.h>

typedef struct {
    int salesID;
    char customerName[50];
    char productName[50];
    int quantity;
    float totalAmount;
} Sale;

void merge(Sale arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    Sale L[n1], R[n2];
    
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        if (L[i].totalAmount >= R[j].totalAmount) 
            arr[k++] = L[i++];
        else 
            arr[k++] = R[j++];
    }
    
    while (i < n1) 
        arr[k++] = L[i++];
    
    while (j < n2) 
        arr[k++] = R[j++];
}

void mergeSort(Sale arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    Sale sales[100];
    int n;

    printf("Enter number of sales records: ");
    scanf("%d", &n);

    printf("Enter sales data (Sales ID, Customer Name, Product Name, Quantity, Total Amount):\n");
    for (int i = 0; i < n; i++) {
        printf("Enter record %d:\n", i + 1);
        scanf("%d%s%s%d%f", &sales[i].salesID, sales[i].customerName, sales[i].productName, &sales[i].quantity, &sales[i].totalAmount);
    }

    mergeSort(sales, 0, n - 1);

    printf("\nSales Data sorted by Total Sale Amount (Descending):\n");
    for (int i = 0; i < n; i++) {
        printf("Sales ID: %d, Customer Name: %s, Product: %s, Quantity: %d, Total Amount: %.2f\n",
               sales[i].salesID, sales[i].customerName, sales[i].productName, sales[i].quantity, sales[i].totalAmount);
    }

    return 0;
}
