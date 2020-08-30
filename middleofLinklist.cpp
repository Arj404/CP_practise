#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

node *newnode(int d)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = d;
    temp->next = NULL;
    return temp;
}

node *middlel(node *head)
{
    node *fpt, *spt;
    if (!head)
    {
        return head;
    }
    fpt = spt = head;
    while (fpt && fpt->next)
    {
        fpt = fpt->next->next;
        spt = spt->next;
    }
    return spt;
}

int main()
{
    int n, a;
    cin >> n;
    node *head, *ptr;
    cin >> a;
    head = newnode(a);
    ptr = head;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a;
        ptr->next = newnode(a);
        ptr = ptr->next;
    }
    node *middle;
    middle = middlel(head);
    cout << middle->data << endl;
    return 0;
}