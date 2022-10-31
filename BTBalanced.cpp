#include<iostream>
#include<queue>
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

int height(node* root){
    if(root==NULL) return 0;
    return max(height(root->left),height(root->right))+1;
}


// Time Complexity = O(n^2);
bool isBalanced(node* root){
    if(root==NULL) return true;

    if(!isBalanced(root->left)) return false;
    if(!isBalanced(root->right)) return false;

    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh)<=1) return true;
    else return false;
}

// Time Complexity = O(n);
bool isBalance(node* root, int* height){
    if(root==NULL) return true;

    int lh = 0, rh = 0;
    if(isBalance(root->left,&lh)==false) return false;
    if(isBalance(root->right,&rh)==false) return false;

    *height = max(lh,rh) +1;
    if(abs(lh-rh)<=1) return true;
    else return false;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt","w",stdout);
    #endif

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    int height = 0;

    cout<<isBalanced(root)<<endl;
    cout<<isBalance(root,&height)<<endl;

    root->right->left->left = new node(6);
    root->right->left->left->left = new node(7);

    cout<<isBalanced(root)<<endl;
    cout<<isBalance(root,&height)<<endl;
    

    return 0;
}   
