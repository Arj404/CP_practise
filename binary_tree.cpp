#include <iostream>
#include <bits/stdc++.h>
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

void levelorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<struct node *> q;
    struct node *temp;
    q.push(root);
    while (!q.empty())
    {
        cout << q.front()->data << " : ";
        temp = q.front();
        q.pop();
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}

struct node *deletenode(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == key)
        {
            return NULL;
        }
        else
        {
            return root;
        }
    }
    queue<struct node *> q;
    q.push(root);
    struct node *temp, *keynode;
    keynode = NULL;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->data == key)
        {
            keynode = temp;
        }
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    if (keynode != NULL)
    {
        int x = temp->data;
        struct node *temp2;
        q.push(root);
        while (!q.empty())
        {
            temp2 = q.front();
            q.pop();
            if (temp2 == temp)
            {
                temp2 = NULL;
                delete(temp);
                break;
            }
            if (temp2->left)
            {
                if(temp2->left == temp){
                    temp2->left = NULL;
                    delete (temp);
                    break;
                }
                else{
                    q.push(temp2->left);
                }
            }
            if (temp2->right)
            {
                if(temp2->right == temp){
                    temp2->right = NULL;
                    delete (temp);
                    break;
                }
                else{
                    q.push(temp2->right);
                }
            }
        }
        keynode->data = x;
    }
    return root;
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
    inorder(root);
    cout << endl;
    levelorder(root);
    cout << endl;
    root = deletenode(root,15);
    inorder(root);
    cout << endl;
    return 0;
}