#include <bits/stdc++.h>

using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{

    node *head = new node(10);
    node *temp1 = new node(20);
    node *temp2 = new node(30);
    head->next = temp1;
    temp1->next = temp2;
    print(head);

    return 0;
}