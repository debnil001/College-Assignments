#include<stdio.h>
#include<string.h>
typedef struct
{
    char date[100];
}DATE;

int main(){
    DATE date1,date2;
    printf("Enter Date 1::");
    scanf("%s",date1.date);
    printf("Enter Date 2::");
    scanf("%s",date2.date);
    printf("Date 1:: %s\n",date1.date);;
    printf("Date 2:: %s\n",date2.date);
    if(strcmp(date1.date,date2.date)==0){
        printf("Equal\n");
    }
    else
        printf("Unequal\n");
    return 0;
}
