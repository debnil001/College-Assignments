#include <stdio.h>

void unionSortedArrays(int *arr1, int n1, int *arr2, int n2, int *res, int *n3) {
    int i = 0, j = 0, k = 0;
    
    while(i < n1 && j < n2) {
        if(*(arr1 + i) < *(arr2 + j)) {
            *(res + k) = *(arr1 + i);
            i++;
            k++;
        }
        else {
            *(res + k) = *(arr2 + j);
            j++;
            k++;
        }
    }

    while(i < n1) {
        *(res + k) = *(arr1 + i);
        i++;
        k++;
    }

    while(j < n2){
        *(res + k) = *(arr2 + j);
        j++;
        k++;
    }

    *n3 = k;
}

void display(int *arr, int size) {
    int i=0;
    printf("\n");
    for(i=0;i<size;i++)
        printf("%d, ", *(arr+i));
}

int main()
{
    int arr1[50] = {0}, arr2[50] = {0}, res[100] = {0};
    int i, n1, n2, n3;

    printf("\nEnter size of first array(n1): ");
    scanf("%d", &n1);
    printf("\nEnter elements of frist (sorted)array: \n");
    for(i=0;i<n1;i++)
        scanf("%d", &arr1[i]);

    printf("\nEnter size of second array(n2): ");
    scanf("%d", &n2);
    printf("\nEnter elements of second (sorted)array: \n");
    for(i=0;i<n2;i++)
        scanf("%d", &arr2[i]);

    //display(arr1, n1);
    //display(arr2, n2);
    
    unionSortedArrays(arr1, n1, arr2, n2, res, &n3);
    
    printf("\nThe union of those sorted arrays is :");
    display(res, n3);
    

}