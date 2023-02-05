#include<iostream>
using namespace std;
int pivotIndex(int n) {
    int sum = 0;
    for(int i=1;i<=n;i++)
    sum+=i;
    int temp = 0;
    for(int i=1; i<=n; i++) {
        sum -= i;
        if(temp == sum) return i;
        temp += i;
    }
    return -1;
}
int main(){
    cout<<pivotIndex(8);
}
