
#include<stdio.h>
int fact(int n){
    if(n==0)
        return 1;
    return n*fact(n-1);
}
int main(){
    int n;
    scanf("%d",&n);
    float e;
    int i;
    for(i=1;i<=n;i++){
        e+=((float)i/fact(i));
    }
    printf("%f",e);
    return 0;
}
