#include<iostream>
using namespace std;
class String{
    string s1;
    public:
    String(string s1){
        this->s1=s1;
    }
    string returnString(){
        return this->s1;
    }
};

String join(String s1,String s2){
    string res="";
    res=s1.returnString()+s2.returnString();
    String finalRes(res);
    return finalRes;
}
void show(String s){
    cout<<s.returnString();
}
int main(){
    String s1("debnil"),s2("sarkar");
    String finalRes=join(s1,s2);
    show(finalRes);
    return 0;
}