#include<stdio.h>
#include<math.h>
double factorial(int n){
    if(n==0)
        return 1;
    return factorial(n-1)*n;
}
double res=0;
double COS(double x,int n,double fact){
    if(n==1)
        return x;
    if(n%2==0){
        COS(x,n-1,fact+2);
    	res=res-(pow(x,fact)/factorial(fact));
    }
    else{
    	COS(x,n-1,fact+2);
    	res=res+(pow(x,fact)/factorial(fact));
	}
}
int main(){
    printf("%lf",COS(0.785398,39,0));
    return 0;
}
