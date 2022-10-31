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

int sumAtK(node* root, int k){
    if(root==NULL) return -1;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    int level = 0;
    int sum = 0;

    while(!q.empty()){
        node* node = q.front();
        q.pop();

        if(node!=NULL){
            if(level==k){
                sum+= node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
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

    cout<<sumAtK(root,0)<<endl;
    cout<<sumAtK(root,1)<<endl;
    cout<<sumAtK(root,2)<<endl;

    return 0;
}   