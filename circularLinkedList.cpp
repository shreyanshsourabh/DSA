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

void display(node* head){
    node* n = head;
    do{
        cout<<n->data<<" -> ";
        n = n->next;
    }while(n->next!=head);
    cout<<n->data<<endl;
}

void insertAtFirst(node* &head, int val){
    node* n = new node(val);

    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtLast(node* &head, int val){
    node* n = new node(val);

    if(head==NULL){
        insertAtFirst(head,val);
        return;
    }

    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void DeleteAtLast(node* &head){

    if(head==NULL){
        cout<<"No element to delete"<<endl;
    }

    node* temp = head;
    node* todelete;
    while(temp->next->next!=head){
        temp=temp->next;
    }
    todelete = temp->next;
    temp->next = head;
    
    delete todelete;
}

void DeleteAtFirst(node* &head){
    node* todelete=head;
    node*temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
    head = head->next;
    temp->next = head;

    delete todelete;
    
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt", "w",stdout);
    #endif

    node *head = new node(23);
    node *n2 = new node(46);
    node *n3 = new node(8);

    head->next = n2;
    n2->next = n3;

    n3->next = head;

    display(head);
    insertAtLast(head,56);
    display(head);
    insertAtFirst(head,76);
    display(head);

    DeleteAtLast(head);
    display(head);
    DeleteAtFirst(head);
    display(head);
    
    return 0;
}