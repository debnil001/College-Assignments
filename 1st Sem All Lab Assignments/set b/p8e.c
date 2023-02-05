#include<stdio.h>
int power(int b,int p){
    int res=1;
    for(int i=1;i<=p;i++)
        res=res*b;
    return res;
}
int convertToBinary(int n,int p){
    if(n==0)
        return 0;
    return convertToBinary(n/2,p+1)+(n%2)*power(10,p);
}

// int convertToBinary(int n){
//     int p=0,bin=0;
//     while(n>0){
//         int rem=n%2;
//         // printf("%lf  \n\n",pow(10,p));
//         bin=bin+(rem * power(10,p));
//         // printf("%d\n",bin);
//         p++;
//         n=n/2;
//     }
//     printf("%d",bin);
// }
int main(){
    // printf("Enter binary number::");
    int n=31;
    // scanf("%d",&n);
    int res=convertToBinary(n,0);
    printf("%d",res);
    return 0;
}