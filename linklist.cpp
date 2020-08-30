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

int main()
{
    int n, a;
    cin >> n;
    node *head, *st;
    cin>>a;
    
    head = newnode(a);
    st = head;
    for (int i = 0; i < n-1; i++)
    {
        cin >> a;
        head->next = newnode(a);
        head = head->next;
    }
    
    head = st;
    while (head != NULL)
    {
        cout << head->data << " : ";
        head = head->next;
    }
    cout << endl;
    return 0;
}