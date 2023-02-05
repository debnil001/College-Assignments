#include<stdio.h>
#include<string.h>
void sortCountry(char **c,int n){
    int i,round;
    for(round=1;round<=n-1;round++){
        for(i=0;i<=n-round-1;i++)
        if(strcmp(c[i],c[i+1])>0){
            char *temp=c[i];
            c[i]=c[i+1];
            c[i+1]=temp;
        }
    }
}
void print(char **c,int n){
    int i;
    for(i=0;i<n;i++)
        printf("%s\n",c[i]);
}
int main(){
    char *country[20]={
        "India",
        "Romania",
        "Costa Rica",
        "Afganistan",
        "Argentina",
        "Brazil",
        "Germany",
        "Japan"
    };
    print(country,7);
   sortCountry(country,7);
   printf("\n\nAfter sorting countries::\n\n");
//    printf("%d",);
    print(country,7);
    return 0;
}