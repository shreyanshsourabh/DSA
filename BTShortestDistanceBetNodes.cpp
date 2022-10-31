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

int distance(node* root, int node1, int node2){
    return min(distance(root->left))
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt","w",stdout);
    #endif

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    // root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->right = new node(6);
    root->right->right->right = new node(7);

    LeftView(root);

    

    return 0;
}   
