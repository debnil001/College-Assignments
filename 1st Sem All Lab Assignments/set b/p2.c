#include<stdio.h>
#include<time.h>
int* random_partition(){
    int arr[100];
    int size,i;
    printf("Enter size of the array::");
    scanf("%d",&size);
//    int i;
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    srand(time(0));
    int pivot=rand()%size;
    // printf("%d",arr[pivot]);
    int pivotElement=arr[pivot];
    printf("Random array element is::%d\n",pivotElement);
    printf("First partition is::");
    for(i=0;i<size;i++){
        if(arr[i]<pivotElement)
            printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Second partition is::");
    for(i=0;i<size;i++){
        if(arr[i]>pivotElement)
            printf("%d ",arr[i]);
    }
}
int main(){
    int size;
	random_partition();
return 0;
}
