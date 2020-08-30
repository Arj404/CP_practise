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
    node *temp = (node *)malloc(sizeof(node));
    temp->data = d;
    temp->next = NULL;
    return temp;
}

bool detection(node *head)
{
    node *ftr, *str;
    ftr = str = head;
    while (ftr && ftr->next)
    {
        ftr = ftr->next->next;
        str = str->next;
        if (ftr == str)
        {
            return true;
        }
    }
    return false;
}

void removal(node *head)
{
    node *str, *prev, *ptr, *ftr;
    prev = (node *)malloc(sizeof(node));
    ftr = str = ptr = head;
    bool flag = false;
    while (ftr && ftr->next)
    {
        ftr = ftr->next->next;
        str = str->next;
        if (ftr == str)
        {
            break;
        }
    }
    int i = 0;
    while (str)
    {
        str = str->next;
        i++;
        if (ftr == str)
        {
            break;
        }
    }
    cout<<"lenght of loop  =  "<<i<<endl;
    prev->next = str;
    while (!flag)
    {
        while (str)
        {
            prev = str;
            str = str->next;
            if (str == ptr)
            {
                flag = true;
                break;
            }
            if (ftr == str)
            {
                break;
            }
        }
        if (flag)
        {
            prev->next = NULL;
        }
        ptr = ptr->next;
    }
    prev->next = NULL;
    return;
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
    ptr->next = head->next->next;
    ptr = head;
    int i = 0;
    while (ptr)
    {
        cout << ptr->data << " : ";
        ptr = ptr->next;
        i++;
        if (i > 30)
        {
            break;
        }
    }
    cout << endl;
    if (detection(head))
    {
        removal(head);
    }
    ptr = head;
    cout << "Loop removed" << endl;
    while (ptr)
    {
        cout << ptr->data << " : ";
        ptr = ptr->next;
    }
    cout << endl;
    return 0;
}