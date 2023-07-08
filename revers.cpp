#include <bits/stdc++.h>

using namespace std;

class node
{

public:
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void print(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
void reverse(node *&head)
{
    node *curr = head;
    node *temp = NULL;
    while (curr != NULL)
    {

        // temp = curr->next;
        // curr->next = curr->prev;
        // curr->prev = temp;
        // if (temp == NULL)
        // {
        //     head = curr;
        // }
        // curr = curr->prev;

        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;

        if (temp == NULL) // Reached the last node of the original list
        {
            head = curr; // Update the head to point to the new first node (last node of the original list)
        }
        curr = curr->prev;
    }
    head = temp->prev;
    // node *hk = head;
    // while (hk != NULL)
    // {
    //     cout << hk->data << " ";
    //     hk = hk->next;
    // }
}
int main()
{

    node *head = new node(10);
    node *temp1 = new node(20);
    node *temp2 = new node(30);
    node *temp3 = new node(40);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    temp2->next = temp3;
    temp3->prev = temp2;
    reverse(head);
    // print(head);
    return 0;
}