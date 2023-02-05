#include<string.h>
#include <stdio.h>
#include <malloc.h>
 
char* substring(char*, int, int); 
void main(){
    char num[500];
    scanf("%s",num);
    int flag=1;
    int i;
    char temp;
    for(i=0;i<strlen(num)-1;){
        if(num[i]=='0')
            i++;
        else
        	break;
    }
    char newNum[500];
    strcpy(newNum,substring(num,i+1,strlen(num)));
    char revNum[500];
    char newNumCopy[500];
    strcpy(newNumCopy,newNum);
    strcpy(revNum,strrev(newNum));
    char newRevNum[500];
    for(i=0;i<strlen(revNum)-1;){
        if(revNum[i]=='0')
            i++;
        else
            break;
    }
    printf("Original number is %s\n",newNumCopy);
    strcpy(newRevNum,substring(revNum,i+1,strlen(revNum)));
    printf("Reverse number is %s\n",newRevNum);
    if(strcmp(newNumCopy,newRevNum)==0)
        printf("Palindrome\n");
    else
        printf("Not a palindome");
}
char *substring(char *string, int position, int length) 
{
   char *pointer;
   int c;
   pointer = malloc(length+1);
   if (pointer == NULL){
      printf("Unable to allocate memory.\n");
   }
   for (c = 0 ; c < position -1 ; c++) 
      string++; 
   for (c = 0 ; c < length ; c++)
   {
      *(pointer+c) = *string;      
      string++;   
   }
   *(pointer+c) = '\0';
   return pointer;
}

