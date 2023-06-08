#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int start, int end) {
    int pivotElement = a[end];
    int index = start - 1;
    
    for (int j = start; j < end; j++) {
        if (a[j]<=pivotElement) {
            index++;
            swap(&a[index], &a[j]);
        }
    }
    
    index++;
    swap(&a[index], &a[end]);
    return index;
}

void quickSort(int a[], int start, int end) {
    if (start >= end) {
        return;
    }
    
    int pivot = partition(a, start, end);
    quickSort(a, start, pivot - 1);
    quickSort(a, pivot + 1, end);
}

int main() {
    int a[] = {100, 8, 4, 6, 3, 5, 36, 12, 2};
    int n = sizeof(a) / sizeof(a[0]);
    
    quickSort(a, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    
    return 0;
}
