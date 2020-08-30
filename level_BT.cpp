#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node*left,*right;
};

struct node *newnode(int data){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(struct node *root, int data){
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

int level(struct node *root, struct node *srnode, int lev){
    if(root == NULL){
        return 0;
    }
    if(root == srnode){
        return lev;
    }
    int l = level(root->left, srnode, lev+1);
    if(l!=0){
        return l;
    }
    return level(root->right, srnode, lev+1);
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
    cout<<level(root, root->left->left,1)<<endl;
    return 0;
}