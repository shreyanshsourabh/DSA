#include<iostream>
using namespace std;

class node{
    public:
    int data;                       //data  
    node *next;                     //adress of next node
    node(int val){
        data = val;
        next = NULL;
    }
};

void display(node* n){
    while(n!=NULL){
        cout<<n->data<<" -> ";
        n = n->next;
    }
    cout<<"Null"<<endl;
}

bool detectCycle(node* head){
    node* fast = head;
    node* slow = head;

    while(fast!=NULL && fast->next!= NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

void removeCycle(node* head){
    node* slow=head;
    node* fast=head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(fast!=slow);

    fast = head;
    while(fast->next!=slow->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;


}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt", "w",stdout);
    #endif

    node *head = new node(23);
    node *n2 = new node(46);
    node *n3 = new node(80);
    node *n4 = new node(98);
    node* n5 = new node(110);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n3;

    if(detectCycle(head)){
        cout<<"Detected"<<endl;
        removeCycle(head);
    }
    display(head);

    

    return 0;
}