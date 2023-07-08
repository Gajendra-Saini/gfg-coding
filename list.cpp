#include <bits/stdc++.h>

using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};
void print(Node *head_ref)
{
    Node *temp = head_ref;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void deleteit(Node *&head_ref, int x)
{
    Node *temp = head_ref;
    if (x == 1)
    {
        head_ref = head_ref->next;
        head_ref->prev = NULL;
        delete temp;
    }
    else
    {
        int cnt = 1;
        while (cnt < x - 1)
        {
            temp = temp->next;
            cnt++;
        }
        if (temp->next->next == NULL)
        {
            Node *str = temp->next;
            temp->next = NULL;
            delete str;
        }
        else
        {
            Node *str = temp->next;
            temp->next = str->next;
            str->next->prev = temp;
            delete str;
        }
    }
}
int main()
{

    Node *head_ref = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    Node *temp3 = new Node(40);
    head_ref->next = temp1;
    temp1->prev = head_ref;
    temp1->next = temp2;
    temp2->prev = temp1;
    temp2->next = temp3;
    temp3->prev = temp2;
    print(head_ref);
    cout << endl;
    deleteit(head_ref, 3);
    print(head_ref);
    cout << endl;
    return 0;
}