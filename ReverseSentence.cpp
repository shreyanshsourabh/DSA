#include<iostream>
#include<string>
using namespace std;


class Stack{
    
    string* st;
    int size;
    int top;
    public:

    Stack(int n){
        st = new string;
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

    void push(string valToPush){
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

    string Top(){
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

    
    string s = "Hey, I'm learning stack!";
    Stack st(2*s.length());

    for(int i=0; i<s.length(); i++){
        string word = "";
        while(s[i]!=' ' && i<s.length()){
            word += s[i];
            i++;
        }
        cout<<word<<" ";
        st.push(word);
    }
    cout<<endl;

    while(!st.empty()){
        cout<<st.Top()<<" ";
        st.pop();
    }
    
    return 0;
}