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

vector<struct node *> constructtree(int start, int end)
{
    vector<struct node *> v;
    if (start > end)
    {
        v.push_back(NULL);
        return v;
    }
    for (int i = start; i <= end; i++)
    {
        vector<struct node *> leftSubtree = constructtree(start, i - 1);
        vector<struct node *> rightSubtree = constructtree(i + 1, end);
        for (int j = 0; j < leftSubtree.size(); j++)
        {
            struct node *left = leftSubtree[j];
            for (int k = 0; k < rightSubtree.size(); k++)
            {
                struct node *right = rightSubtree[k];
                struct node *node = newnode(i);
                node->left = left;
                node->right = right;
                v.push_back(node);
            }
        }
    }
    return v;
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " : ";
    inorder(root->left);
    inorder(root->right);
}

int main()
{
    vector<struct node *> totalTreesFrom1toN = constructtree(1, 5);
    cout << "Preorder traversals of all constructed BSTs are \n";
    for (int i = 0; i < totalTreesFrom1toN.size(); i++)
    {
        inorder(totalTreesFrom1toN[i]);
        cout << endl;
    }
    return 0;
}