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


node* reverse(node* &head){
    node* prv = NULL;
    node* curr = head;
    node* next;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prv;

        prv = curr;
        curr = next;
    }

    return prv;
    
}

node* recursivereverse(node* &head){

    if(head==NULL || head->next == NULL){
        return head;
    }
    
    node* newhead = recursivereverse(head->next);
    head->next ->next =head;
    head->next = NULL;

    return newhead;

}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt", "w",stdout);
    #endif

    node *head = new node(23);
    node *n2 = new node(46);
    node *n3 = new node(80);

    head->next = n2;
    n2->next = n3;

    display(head);
    // display(reverse(head));
    display(recursivereverse(head));
    

    return 0;
}