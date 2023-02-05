#include<stdio.h>
#include<math.h>
double fact(int n){
    if(n==1)
    return 1;

    return n*fact(n-1);
}
void main(){
    double x,double sum=0.0;int i,j;
    printf("enter x::");
    scanf("%lf",&x);
    for(i=1,j=1;i<=20;i++,j+=2){
        if(i%2==0)
        sum=sum-(double)(pow(x,j)/fact(j));
        else
        sum=sum+(double)(pow(x,j)/fact(j));
    }
    printf("%lf",sum);
}
