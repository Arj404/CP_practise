#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

struct node *newnode(int data){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(struct node *root,int data){
    if(root == NULL){
        root = newnode(data);
        cout<<"inserted r"<<endl;
        return;
    }
    else if(root->data > data){
        if(!root->left){
            root->left = newnode(data);
            cout<<"inserted l"<<endl;
            return;
        }
        else{
            insert(root->left,data);
        }
    }
    else if(root->data < data){
        if(!root->right){
            root->right = newnode(data);
            cout<<"inserted ri"<<endl;
            return;
        }
        else{
            insert(root->right,data);
        }
    }
    else{
        return;
    }
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " : ";
    inorder(root->right);
}

int main(){
    int n,x;
    struct node *root;
    root=NULL;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if (!root)
        {
            root = newnode(x);
        }
        else
        {
            insert(root, x);
        }
    }
    inorder(root);
    return 0;
}