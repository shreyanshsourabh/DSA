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

void insertAtLast(node* &head,int val){
    node *n = new node(val);

    if(head==NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp = temp ->next;
    }
    temp ->next = n;

}

void insertAtFirst(node* &head, int val){
    node *n = new node(val);

    n->next = head;
    head = n;
}

void searchAndInsert(node* &head, int key, int val){
    node* n = new node(val);

    node* temp = head;
    while(temp!=NULL){
        if(temp->data == key){
            node* t = temp->next;
            temp->next = n;
            n->next = t;
            return; 
        }
        temp = temp->next;
    }
    insertAtLast(head,val);
}

void deleteAtLast(node* &head){
    if(head==NULL){
        cout<<"No Values"<<endl;
        return;
    }

    node* temp = head;
    while((temp->next) ->next != NULL){
        temp = temp->next;
    }
    node* toDelete = temp->next;
    delete toDelete;
    temp->next =  NULL;
    

}

void deleteAtFirst(node* &head){
    node* temp = head;
    node* toDelete = temp;
    delete toDelete;
    head = head->next;
    
}

void searchAndDelete(node* &head,int key){
    node* temp = head;
    while(temp->next!=NULL){
        if((temp->next)->data == key){
            temp->next = (temp->next) -> next;
            node* toDelete = temp->next;
            delete toDelete;
            return;
        }
        temp = temp->next;
    }
    
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

    display(head);
    insertAtLast(head,89);
    display(head);
    insertAtFirst(head,64);
    display(head);
    searchAndInsert(head,47,29);
    display(head);

    deleteAtLast(head);
    display(head);
    deleteAtFirst(head);
    display(head);
    searchAndDelete(head,46);
    display(head);
    

    return 0;
}