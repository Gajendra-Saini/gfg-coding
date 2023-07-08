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
node *reverse(node *&head)
{
    node *temp = head; // temp is pointing to 10
    // node *str = NULL;
    while (temp != NULL) // tu temp->next null nahi kr sakta because voh puri iterations se pahle he dam todh dega str=temmp->next hoga tab last mai voh
    {
        node *str = temp->next;
        temp->next = temp->prev;
        temp->prev = str;
        if (str == NULL) // in the last node it is pointing to null that is porblem
        {
            return temp;
            // if you don't use this then you use space joh available nahi hai se segmentation fault
        }

        temp = temp->prev;
    }
    return temp; // in the end temp last vale ko point kr rha hoga
}
// node *reverse(node *&head)
// {
//     node *temp = head; // temp is pointing to 10
//     node *str = NULL;
//     while (temp != NULL) // tu temp->next null nahi kr sakta because voh puri iterations se pahle he dam todh dega str=temmp->next hoga tab last mai voh
//     {
//         str = temp->prev;
//         temp->prev = temp->next;
//         temp->next = str;
//         temp = temp->prev;
//     }
//     return str->prev; // in the end temp last vale ko point kr rha hoga
//     // note that str temp se 2 distance piche hoga so temp null pr hoga str secodn last pr hoga so str->prev sab thik kr dega
// }
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
    print(head);
    cout << endl;
    head = reverse(head); // you have pass 10 20 30 40
    print(head);
    return 0;
}