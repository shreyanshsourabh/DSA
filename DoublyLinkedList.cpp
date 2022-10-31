#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }

};

void insertAtFirst(node* &head, int val){
    node *n = new node(val);

    n->next = head;
    head->prev = n;

    head = n;
}

void insertAtLast(node* &head, int val){
    node* n = new node(val);

    if(head==NULL){
        insertAtFirst(head,val);
        return;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void display(node* &head){
    cout<<"NULL <-> ";
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteAtFirst(node* &head){
    node* temp = head;
    head = head->next;
    head->prev = NULL;

    delete temp;

}

void searchandDelete(node* &head, int key){
    if(head->prev == NULL ){
        deleteAtFirst(head);
        return;
    }

    node* temp = head;
    while(temp->data!=key && temp!=NULL){
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    if(temp->next!=NULL) temp->next->prev = temp->prev;

    delete temp;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt", "w",stdout);
    #endif

    node *head = new node(23);
    node *n2 = new node(46);
    node *n3 = new node(25);
    node *n4 = new node(79);

    head->next = n2;
    n2->next = n3;
    n2->prev = head;

    n3->next = n4;
    n3->prev = n2;

    n4->prev =n3;

    display(head);
    insertAtLast(head,100);
    display(head);
    insertAtFirst(head,12);
    display(head);
    searchandDelete(head,23);
    display(head);
    

    return 0;
}