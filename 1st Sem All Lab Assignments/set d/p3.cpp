#include<iostream>
using namespace std;
class Number_List{
    int *arr;
    int size;
    public:
    void allocateArray(int size){
        arr=new int[size];
        this->size=size;
    }
    void takeNums();
    void show();
    void sort();
    void maxmin();
};
void Number_List::takeNums(){
    cout<<"Enter numbers::";
    for(int i=0;i<size;i++)
    cin>>arr[i];
}
void Number_List::sort(){
    for(int round=1;round<=size-1;round++){
        for(int j=0;j<=size-round-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"Sorted"<<endl;
}
void Number_List::maxmin(){
    cout<<"Maximum number is::"<<arr[size-1]<<endl;
    cout<<"Minimum number is::"<<arr[0]<<endl;
}
void Number_List::show(){
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    Number_List num;
    num.allocateArray(10);
    num.takeNums();
    num.show();
    num.sort();
    num.show();
    num.maxmin();
    return 0;
}