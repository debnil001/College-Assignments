#include<iostream>
using namespace std;
class Time{
    int hour,min,sec;
    public:
    friend ostream& operator<<(ostream&,Time&);
    friend istream& operator>>(istream&,Time&);
    Time operator+(Time&);
    bool operator==(Time&);
    void show();
};
ostream& operator<<(ostream& output,Time& t){
    output<<t.hour<<":"<<t.min<<":"<<t.sec<<endl;
    return output;
}
istream& operator>>(istream& input,Time& t){
    cout<<"Enter time hour min and second::";
    input>>t.hour>>t.min>>t.sec;
    return input;
}
void Time::show(){
    cout<<hour<<":"<<min<<":"<<sec<<endl;
}
Time Time::operator+(Time& that){
    Time temp;
    temp.sec=this->sec+that.sec;
    temp.hour=this->hour+that.hour;
    temp.min=this->min+that.min;
    if(temp.sec>=60){
        temp.min+=temp.sec/60;
        temp.sec=temp.sec%60;
    }
    if(temp.min>=60){
        temp.hour+=temp.min/60;
        temp.min=temp.min%60;
    }
    return temp;
}
bool Time::operator==(Time& that){
    if(this->hour!=that.hour)
        return false;
    else if(this->min!=that.min)
        return false;
    else if(this->sec!=that.sec)
        return false;
    else
        return true;
}
int main(){
    Time t1,t2;
    cin>>t1>>t2;
    cout<<t1<<t2;
    if(t1==t2)
        cout<<"Two times are equal"<<endl;
    else
        cout<<"Two times are not equal"<<endl;
    Time totalTime=t1.operator+(t2);
    totalTime.show();
    return 0;
}
