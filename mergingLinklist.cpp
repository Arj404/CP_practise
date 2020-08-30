#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

node *newnode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

node *merge(node *head1, node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    node *head3, *temp;
    if (head1->data < head2->data)
    {
        temp = newnode(head1->data);
        head1 = head1->next;
    }
    else
    {
        temp = newnode(head2->data);
        head2 = head2->next;
    }
    head3 = temp;
    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            temp->next = newnode(head1->data);
            temp = temp->next;
            head1 = head1->next;
        }
        else
        {
            temp->next = newnode(head2->data);
            temp = temp->next;
            head2 = head2->next;
        }
    }
    while (head1)
    {
        temp->next = newnode(head1->data);
        temp = temp->next;
        head1 = head1->next;
    }
    while (head2)
    {
        temp->next = newnode(head2->data);
        temp = temp->next;
        head2 = head2->next;
    }
    cout << "we" << endl;
    return head3;
}

int main()
{
    int n, a;
    cin >> n;
    node *head1, *temp, *head2;
    cin >> a;
    temp = newnode(a);
    head1 = temp;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a;
        temp->next = newnode(a);
        temp = temp->next;
    }
    temp = NULL;
    cin >> n;
    cin >> a;
    temp = newnode(a);
    head2 = temp;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a;
        temp->next = newnode(a);
        temp = temp->next;
    }
    node *head3;
    head3 = merge(head1, head2);
    while (head3 != NULL)
    {
        cout << head3->data << " : ";
        head3 = head3->next;
    }
    cout << endl;
    return 0;
}