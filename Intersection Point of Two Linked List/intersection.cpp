// Time Complexity is O(length of Bigger linked list)

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node *&head, int data)
{

    Node *newTail = new Node(data);
    if (head == NULL)
    {
        head = newTail;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newTail;
    newTail->next = NULL;
}

void intersect(Node *head1, Node *head2, int pos)
{
    pos--;
    Node *curr1 = head1;
    while (pos--)
    {
        curr1 = curr1->next;
    }
    Node *curr2 = head2;
    while (curr2->next != NULL)
    {
        curr2 = curr2->next;
    }
    curr2->next = curr1;
}

int length(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void intersection(Node *&head1, Node *&head2)
{
    Node *curr1 = head1;
    Node *curr2 = head2;
    int count1 = length(head1);
    int count2 = length(head2);
    if (count1 > count2)
    {
        int count = 0;
        int res = count1 - count2;
        while (count != res)
        {
            curr1 = curr1->next;
            count++;
        }
        if (curr1 == NULL)
        {
            cout << "No Intersection found" << endl;
            return;
        }
        while (curr1 != NULL and curr2 != NULL)
        {
            if (curr1->data == curr2->data)
            {
                cout << "The intersection point is " << curr1->data << endl;
                return;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }
    else
    {
        int res = count2 - count2;
        while (count2 != res)
        {
            curr2 = curr2->next;
            count2++;
        }
        while (curr1 != NULL and curr2 != NULL)
        {
            if (curr1 == curr2)
            {
                cout << "The intersection point is" << curr1->data << endl;
            }
        }
    }
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";
    cout << endl;
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 6);
    display(head1);
    insertAtTail(head2, 9);
    insertAtTail(head2, 10);
    insertAtTail(head2, 5);
    insertAtTail(head2, 6);
    // intersect(head1, head2, 3);
    display(head2);
    intersection(head1, head2);
    // display(head);
}