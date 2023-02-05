#include<stdio.h>
#include<math.h>
double fact(int n){
    if(n==0)
    return 1;

    return n*fact(n-1);
}
void main(){
    double x,sum=0.0;int i,j;
    printf("enter x::");
    scanf("%lf",&x);
    for(i=1,j=0;i<40;i++,j+=2){
        if(i%2==0)
        sum=sum-(double)(pow(x,j)/fact(j));
        else
        sum=sum+(double)(pow(x,j)/fact(j));
    }
    if(sum<0)
    	sum=0;
    printf("%lf",sum);
}
