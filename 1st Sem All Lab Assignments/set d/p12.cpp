#include<iostream>
using namespace std;

void operator+(string s1,string s2){
    string s3=s1.append(s2);
    for(int i=0;i<s3.length()/2;i++){
        char temp=s3[i];
        s3[i]=s3[s3.length()-i-1];
        s3[s3.length()-i-1]=temp;
    }
    cout<<"Reversed concatenated string is::"<<s3;
}
int main(){
    string s1="debnil";
    string s2="sarkar";
    operator+(s1,s2);
    return 0;
}