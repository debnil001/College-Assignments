#include<stdio.h>
#include<math.h>
int main(){
    double x,n,sign=1;
    double sum=0;int i;
    printf("Enter x::");
    scanf("%lf",&x);
    if(x<-1 && x>1)
	{
		printf("The value of x must be between -1 to 1.\n");
		return(0);
	}
    for(i=1;i<=20;i++){
        sum=sum+(sign)*((double)pow(x,i)/i);
        sign*=-1;
    }
    printf("%lf",sum);
    return 0;
}
