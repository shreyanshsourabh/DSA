#include<iostream>
using namespace std;

class Stack{
    
    int* st;
    int top;
    int size;
    public:

    Stack(int n){
        st = new int[n];
        size = n;
        top = -1;
    }

    void display(){
        if(top==-1){
            cout<<"No elements"<<endl;
            return;
        }
        if(top>=size){
            cout<<"Overflow"<<endl;
            return;
        }
        for(int i=0; i<=top; i++){
            cout<<st[i]<<" ";
        }
        cout<<endl;
    }

    void push(int valToPush){
        if(top>=size){
            return display();
        }

        top++;
        st[top] = valToPush;
    }

    void pop(){
        if(top==-1){
            return display();
        }
        top--;
    }

    int Top(){
        if(top==-1){
            display();
        }
        return st[top];
    }

    bool empty(){
        return top==-1;
    }

};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt", "w",stdout);
    #endif

    Stack st(3);
    cout<<st.empty()<<endl;
    st.push(45);
    st.push(98);
    st.push(110);
    st.display();
    cout<<st.Top()<<endl;
    st.pop();
    st.display();
    cout<<st.Top()<<endl;
    cout<<st.empty()<<endl;
    
    return 0;
}