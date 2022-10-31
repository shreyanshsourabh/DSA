#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int search(int in[], int s, int e, int curr){
    for(int i=s; i<=e; i++){
        if(in[i]==curr){
            return i;
        }
    }
    return -1;
}

node* buildTree(int post[], int in[], int s, int e){
    static int idx = e;

    if(s>e){
        return NULL;
    }

    int curr = post[idx];
    idx--;
    node* n = new node(curr);

    if(s==e) return n;
    int pos = search(in,s,e,curr);
    n->right = buildTree(post,in,pos+1,e);
    n->left = buildTree(post,in,s,pos-1);

    return n;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt","w",stdout);
    #endif

    // int pre[] = {1, 2, 4, 5, 3, 6, 7} ;
    int in[] = {4, 2, 5, 1, 6, 3, 7};
    int post[] = {4, 5, 2, 6, 7, 3, 1};

    node* root = buildTree(post,in,0,6);
    inorder(root); 

    return 0;
}   