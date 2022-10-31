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

int length(node* &head){
    int count=0;
    node* temp=head;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

node* appendLastKNodes(node* &head, int k){
    int l = length(head);
    k=k%l;
    int count = 1; 
    node* tail = head;
    node* newTail;
    node* newHead;

    while(tail->next!=NULL){
        if(count==l-k){
            newTail = tail;
        }
        if(count==l-k+1){
            newHead = tail;
        }

        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;
    return newHead;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt", "w",stdout);
    #endif

    node *head = NULL;
    int arr[6] = {1,2,3,4,5,6};
    for(int i=0; i<6; i++){
        insertAtLast(head,arr[i]);
    }
    display(head);
    cout<<length(head)<<endl;
    display(appendLastKNodes(head,3));
    

    return 0;
}