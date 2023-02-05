#include<iostream>
using namespace std;

class STACK{
	protected:
    	int stack[50];
    	int top;
    public:
        STACK(){
            top=-1;
        }
        void push(int);
        int pop();
        int peek();
        bool isEmpty();
};
void STACK::push(int x){
    top++;
    stack[top]=x;
}
int STACK::pop(){
    if(top==-1)
        return -1;
    int item=stack[top];
    top--;
    return item;
}
int STACK::peek(){
    return stack[top];
}
bool STACK::isEmpty(){
    if(top==-1)
    	return false;
    return true;
}
class SPECIAL_STACK:public STACK{
    public:
        void push(int x);
};

void SPECIAL_STACK::push(int x){
    if(top==-1){
        top++;
        stack[top]=x;
    }
    else{
        if(x<stack[top]){
            top++;
            stack[top]=x;
        }
        else{
            cout<<"Not possible to push "<<x<<endl;
        }
    }
}
int main(){
    SPECIAL_STACK st;
    STACK stck;
    stck.push(5);
    stck.push(40);
    stck.push(3);
    stck.push(60);
    cout<<stck.peek()<<"\n";
    while()
    cout<<"element "<<st.pop()<<" popped"<<endl;
    cout<<"element "<<st.pop()<<" popped"<<endl;
    cout<<st.peek()<<"\n";
    return 0;
}
