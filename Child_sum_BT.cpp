#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newnode(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(struct node *root, int data)
{
    queue<struct node *> q;
    struct node *temp;
    q.push(root);
    while (!q.empty())
    {
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

bool childsum(struct node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    if (root->left == NULL && root->right != NULL)
    {
        if (root->data == root->right->data)
        {
            return 1 && childsum(root->right);
        }
        else
        {
            return 0;
        }
    }
    if (root->left != NULL && root->right == NULL)
    {
        if (root->data == root->left->data)
        {
            return 1 && childsum(root->left);
        }
        else
        {
            return 0;
        }
    }
    if (root->left != NULL && root->right != NULL)
    {
        if (root->data == root->right->data + root->left->data)
        {
            return 1 && childsum(root->right) && childsum(root->left);
        }
        else
        {
            return 0;
        }
    }
    return 0;
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
    bool flag;
    flag = childsum(root);
    cout << flag << endl;
    return 0;
}