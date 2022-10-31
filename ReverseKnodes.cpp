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


node* recursivereverse(node* &head){

    if(head==NULL || head->next == NULL){
        return head;
    }
    
    node* newhead = recursivereverse(head->next);
    head->next ->next =head;
    head->next = NULL;

    return newhead;

}

node* reversek(node* &head, int k){
    node* prv = NULL;
    node* curr = head;
    node* nxt;

    int count = 0;
    while(curr!=NULL && count<k){
        nxt = curr->next;
        curr->next = prv;

        prv = curr;
        curr = nxt;

        count++; 
    }

    if(nxt!=NULL){
        head->next = reversek(nxt,k);
    }
    return prv;
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

    display(head);
    // display(reverse(head));
    display(reversek(head,3));
    

    return 0;
}