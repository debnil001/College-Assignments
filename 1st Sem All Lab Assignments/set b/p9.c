#include<string.h>
#include<stdio.h>
int findSubstr(char str[],char substr[]){
    int strl=strlen(str),substrlen=strlen(substr);
    int i,j,flag;
    for(i=0;i<strl;i++){
        for(j=0;j<substrlen;j++){
            if(str[i+j]!=substr[j]){
                flag=0;
                break;
            }
            flag=1;
        }
        if(flag==1)
            break;
    }
    if(flag==1)
        return i;
    else
        return 0;
}
main(){
    char str[100],substr[50];
    printf("Enter a string::");
    gets(str);
    printf("Enter a substring::");
    gets(substr);
    int idx=findSubstr(str,substr);
    printf("Substr occured at %d index in str",idx);
}