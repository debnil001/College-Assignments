#include<string.h>
#include<stdio.h>
char sym[]={'A','B','C','D','E','F','\0'};
char res[100];
void convertToBase(int n,int base){
    int c=0;
    while(n!=0){
    	int num=(n%base);
    	if(num>9){
    		res[c++]=sym[num%10];
		}	
    	else
        	res[c++]=48+num;
        n=n/base;
    }
    res[c]='\0';
    int i;
    for(i=strlen(res)-1;i>=0;i--){
    	printf("%c",res[i]);
	}
}
int main(){
    int n,base;
    printf("Enter a decimal number::");
    scanf("%d",&n);
    printf("enter base to convert::");
    scanf("%d",&base);
    convertToBase(n,base);
    return 0;
}
