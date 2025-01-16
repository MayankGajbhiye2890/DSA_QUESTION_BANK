// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

//stacks using arrays
class Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(int size){
        this->arr = new int[size];
        this->size = size;
        this->top = -1;
    }
    void push(int data){
        if(top<size-1){
            top++;
            arr[top] = data;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }
    void pop(){
        if(top<0){
            cout<<"stack underflow"<<endl;
        }
        else{
            top--;
        }
    }
    int gettop(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
            
            return -1;
        }
       return arr[top];
    }
    
    bool empty(){
        if(top == -1){
            return true;
        }
        return false;
    }
    int getsize(){
        return top+1;
    }
};



//stacks using queues

class Stacks{
    private:
    queue<int>q1;
    queue<int>q2;
    //int size;
    public:

    void push(int x){
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }

    void pop(){
        if(q1.empty()){
            cout<<"stack underflow "<<endl;
        }
        q1.pop();
    }

    int top(){
        if(q1.empty()){
            cout<<"stack is empty"<<endl;
        }
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }
    int size(){
        return q1.size();
    }
};

int main() {
    
    Stack st(5);
    st.push(10);
    st.pop();
    st.gettop();
    st.getsize();
    cout<<st.getsize();
    return 0;
}