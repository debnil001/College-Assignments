#include<stdio.h>
int isPrime(int num){
	int i;
	for(i=2;i<num;i++){
		if(num%i==0)
			return 0;
	}
	return 1;
}
main(){
    int n;
    printf("Enter n::");
    scanf("%d",&n);
    int prime=2;
    long long int sum=0;
    long long int temp;
    int temp1,temp2;
    while(n!=0){
    	temp=1;
        if(isPrime(prime)){
            temp1=prime;
        }
        prime++;
        while(!isPrime(prime)){
            prime++;
        }
        temp2=prime;
        sum=sum+(temp1*temp2);
        n--;
    }
    printf("%lli",sum);
}
