#include<iostream>
using namespace std;
class Pattern{
    int row;
    public:
    Pattern(int row){
        this->row=row;
    }
    void printPattern();
};
void Pattern::printPattern(){
    for(int i=row;i>=1;i--){
        for(int sp=1;sp<=row-i;sp++)
                cout<<" ";
        for(int j=1;j<=i*2-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
int main(){
    Pattern obj(6);
    obj.printPattern();
}