#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int data)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    return t;
}

void insert(struct node *root, int data)
{
    queue<struct node *> q;
    q.push(root);
    while (!q.empty())
    {
        struct node *temp;
        temp = q.front();
        q.pop();
        if (!temp->left)
        {
            temp->left = newnode(data);
            return;
        }
        else
        {
            q.push(temp->left);
        }
        if (!temp->right)
        {
            temp->right = newnode(data);
            return;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

int sum(struct node *root){
    if(root == NULL){
        return 0;
    }
    else{
        return root->data + sum(root->left) + sum(root->right);
    }
}

bool sumtree(struct node *root){
    if(root == NULL || (root->left==NULL && root->right==NULL) ){
        return 1;
    }
    else{
        //cout<<sum(root->left) + sum(root->right)<< " : " <<root->data<<endl;
        if(root->data == sum(root->left) + sum(root->right)){
            return 1 && sumtree(root->left) && sumtree(root->right);
        }
        else{
            return 0;
        }
    }
}

int main()
{
    int n, d;
    cin >> n;
    struct node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        if (!root)
        {
            root = newnode(d);
        }
        else
        {
            insert(root, d);
        }
    }
    cout<<sumtree(root)<<endl;
    return 0;
}