#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int *ptr;
    int capacity;
    int lastIndex;
}Array;
Array* create(){
    Array *array=(Array*)malloc(sizeof(Array));
    array->capacity=5;
    array->ptr=(int*)malloc(sizeof(int)*(array->capacity));
    array->lastIndex=-1;
    return array;
}
void doubleArraySize(Array **array){
	int *temp,i;
	temp=(int*)malloc(sizeof(int)*(((*array)->capacity)+10));
	for(i=0;i<=(*array)->lastIndex;i++)
	  temp[i]=(*array)->ptr[i];
	free((*array)->ptr);
	(*array)->ptr=temp;
	(*array)->capacity+=10;
}

void insert(Array** array,int val){
    (*array)->lastIndex++;
    (*array)->ptr[(*array)->lastIndex]=val;
    if((*array)->lastIndex>=(*array)->capacity){
        doubleArraySize(array);
        printf("\nArray Size Increased\n");
    }
}
void printError(){
    printf("Array is empty\n");
}
void display(Array **array){
    if((*array)->lastIndex==-1){
        printError();
        return;
    }
    int i;
	for(i=0;i<=(*array)->lastIndex;i++){
        printf("%d ",(*array)->ptr[i]);
    }
    printf("\n");
}
void delete(Array** array,int val){
    if((*array)->lastIndex==-1){
        printError();
        return;
    }
    int i,j;
    for(i=0;i<=(*array)->lastIndex;i++){
        if(val==(*array)->ptr[i]){
            for(j=i;j<(*array)->lastIndex;j++){
                (*array)->ptr[j]=(*array)->ptr[j+1];
            }
            (*array)->lastIndex--;
            printf("Array after deletion::");
            display(array);
            return;
        }
    }
    printf("\nValue not found\n");
}
void sort(Array **array){
    if((*array)->lastIndex==-1){
        printError();
        return;
    }
    int round,j;
    int size=(*array)->lastIndex+1;
    for(round=1;round<=size-1;round++){
        for(j=0;j<=size-round-1;j++){
            if((*array)->ptr[j]>(*array)->ptr[j+1]){
                int temp=(*array)->ptr[j];
                (*array)->ptr[j]=(*array)->ptr[j+1];
                (*array)->ptr[j+1]=temp;
            }
        }
    }
    printf("Sorted array is::");
    display(array);
}
void reverse(Array** array){
    if((*array)->lastIndex==-1){
        printError();
        return;
    }
    int size=(*array)->lastIndex+1;
    int i;
    for(i=0;i<size/2;i++){
        int temp=(*array)->ptr[i];
        (*array)->ptr[i]=(*array)->ptr[size-i-1];
        (*array)->ptr[size-i-1]=temp;
    }
    printf("Reverse array is::");
    display(array);
}
void showAllOccur(Array** array,int val){
    if((*array)->lastIndex==-1){
        printError();
        return;
    }
    int i,flag=0;
    for(i=0;i<=(*array)->lastIndex;i++){
        if((*array)->ptr[i]==val){
            printf("%d found at index %d\n",val,i);
            flag=1;
        }
    }
    if(flag==0){
        printf("Element not found");
        return;
    }
}
void showElement(Array** array,int index){
    if((*array)->lastIndex==-1){
        printError();
        return;
    }
    int i,flag=0;
    if(index<0 || index>(*array)->lastIndex){
        printf("Invalid index\n");
        return;
    }
    printf("%d is present at index %d",(*array)->ptr[index],index);
}
void split(Array** array1,Array** array2,int pos){
    if((*array1)->lastIndex==-1){
        printError();
        return;
    }
    if(pos>=(*array1)->lastIndex){
        printf("Not possible");
        return;
    }
    int size=(*array1)->lastIndex-pos;
    int *temp=(int*)malloc(sizeof(int)*size);
    int i;
    for(i=pos+1;i<=(*array1)->lastIndex;i++){
    	insert(array2,(*array1)->ptr[i]);
    }
    (*array1)->lastIndex=pos;
    printf("Main array is::");
    display(array1);
    printf("Sub array is::");
    display(array2);
}
void merge(Array** array1,Array** array2){
    if((*array1)->lastIndex==-1){
        printError();
        return;
    }
    if((*array2)->lastIndex==-1){
    	printf("No subarray found....first split the array then try to merge\n");
    	return;
	}
    int i;
    for(i=0;i<=(*array2)->lastIndex;i++){
		insert(array1,(*array2)->ptr[i]);
	}
    printf("Merged array is::");
    display(array1);
}
void count(Array** array){
    if((*array)->lastIndex==-1){
        printError();
        return;
    }
    printf("Count of element in the array is %d",(*array)->lastIndex+1);
}

void search(Array** array,int val){
    int i,flag=0;
    for(i=0;i<=(*array)->lastIndex;i++){
        if((*array)->ptr[i]==val){
            printf("%d found at index %d",val,i);
            return;
        }
    }
    printf("Element not found");    
}
int main(){
    Array *array=create();
    Array *array1=create();
    int choice;
    int val;
    while(1){
        printf("\n\n1) Create\n"
        "2) Insert\n"
        "3) Display the entire list\n"
        "4) Count\n"
        "5) Reverse the list\n"
        "6) Index of a given element\n"
        "7) Indexed element \n"
        "8) Delete \n9) Merge\n"
        "10) Split \n11) Sort\n"
        "12) Search\n");
        printf("Enter choice::");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("\nArray Created\n");
                break;
            case 2:
                printf("\nEnter value ::\n");
                scanf("%d",&val);
                insert(&array,val);
                printf("\nValue inserted\n");
                break;
            case 3:
                printf("Array elements are ::");
                display(&array);
                break;
            case 4:
                count(&array);
                break;
            case 5:
                
                reverse(&array);
                break;
            case 6:
                printf("\nEnter index ::");
                scanf("%d",&val);
                showAllOccur(&array,val);
                break;
            case 7:
                printf("\nEnter index ::");
                scanf("%d",&val);
                showElement(&array,val);
                break;
            case 8:
                printf("\nEnter value to delete ::");
                scanf("%d",&val);
                delete(&array,val);
                break;
            case 9:
                merge(&array,&array1);
                break;
            case 10:
                printf("\nEnter position to split ::");
                scanf("%d",&val);
                split(&array,&array1,val);
                break;
            case 11:
                sort(&array);
                break;
            case 12:
                printf("\nEnter value to search ::");
                scanf("%d",&val);
                search(&array,val);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }    
    }
}
