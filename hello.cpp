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
void isloop(node *head)
{
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "yes";
            return;
        }
    }
    cout << "no";
}
int lengthofloop(node *head)
{
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            int cnt = 1;
            slow = slow->next;
            while (slow != fast)
            {
                slow = slow->next;
                cnt++;
            }
            return cnt;
        }
    }
    return 0;
}
int starting(node *head)
{
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow->next->data;
        }
    }
    return -1;
}
int main()
{
    node *head = new node(1);
    node *first = new node(2);
    node *second = new node(3);
    node *third = new node(4);
    node *fourth = new node(5);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    // fourth->next = NULL;
    fourth->next = third;
    // isloop(head);
    // cout << "length os loop is " << lengthofloop(head) << endl;
    cout << "start of loop is " << starting(head) << endl;

    return 0;
}