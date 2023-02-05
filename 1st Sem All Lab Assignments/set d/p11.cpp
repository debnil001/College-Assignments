#include<iostream>
using namespace std;
void reverse(int m){
    int rev=0;
    while(m!=0){
        int rem=m%10;
        rev=rev*10+rem;
        m/=10;
    }
    cout<<"Reverse number is "<<rev<<endl;
}
void checkPrime(int m){
    if(m<2)
        cout<<"Number is not prime"<<endl;
    int i;
    for( i=2;i<m;i++){
        if(m%i==0)
            break;
    }
    if(i==m)
        cout<<"Prime number"<<endl;
    else    
        cout<<"Not a prime number"<<endl;
}
void calculate(int m,char ch){
    if(ch=='r'){
        reverse(m);
    }
    else if(ch=='m'){
        checkPrime(m);
    }
}
int main(){
    calculate(147,'r');
    calculate(147,'m');

    return 0;
}