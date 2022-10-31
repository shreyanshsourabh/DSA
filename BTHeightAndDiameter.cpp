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

// Time Complexity for height = O(n);
int height(node* root){
    if(root==NULL) return 0;
    return max(height(root->left),height(root->right))+1;
}

// Time Complexity for diameter = O(n^2);
int diameter(node* root){
    if(root==NULL) return 0;
    return max((height(root->left)+height(root->right)+1),max(diameter(root->left),diameter(root->right)));
}

// Time Complexity for calDiameter = O(n);
int calDiameter(node* root, int* height){
    if(root==NULL){
        *height = 0;
        return 0;
    }

    int lh =0, rh =0;
    int ld = calDiameter(root->left,&lh);
    int rd = calDiameter(root->right,&rh);

    int currDia = lh+rh+1;
    *height = max(lh,rh)+1;

    return max(currDia,max(ld,rd));
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
    // root->left->right = new node(5);

    root->right->left = new node(6);
    // root->right->right = new node(7);

    cout<<height(root)<<endl;
    cout<<diameter(root)<<endl;

    int h = 0;
    cout<<calDiameter(root,&h)<<endl;

    return 0;
}   
