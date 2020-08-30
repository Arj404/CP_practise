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
    node *temp,*prev,*result;
    prev = (node *)malloc(sizeof(node));
    prev->next = head1;
    result = head1;
    bool flag = true;
    while(head1 && head2){
        if(head1->data > head2->data){
            prev->next = head2;
            temp = head2->next;
            head2->next = head1;
            head2 = temp;
            prev = prev->next;
        }
        else{
            prev = head1;
            head1 = head1->next;
        }
        if(flag){
            result = prev;
            flag = false;
        }
    }
    if(head2){
        prev->next = head2;
    }
    return result;
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
    while (head3)
    {
        cout << head3->data << " : ";
        head3 = head3->next;
    }
    cout << endl;
    return 0;
}