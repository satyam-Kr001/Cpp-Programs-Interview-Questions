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

Node *mergingTwoList(Node *&head1, Node *&head2)
{
    Node *dummyNode = new Node(-1);
    Node *ptr = dummyNode;
    Node *curr1 = head1;
    Node *curr2 = head2;
    while (curr1 != NULL and curr2 != NULL)
    {
        if (curr1->data < curr2->data)
        {
            ptr->next = curr1;
            curr1 = curr1->next;
        }
        else
        {
            ptr->next = curr2;
            curr2 = curr2->next;
        }
        ptr = ptr->next;
    }
    if (curr1)
    {
        while (curr1 != NULL)
        {
            ptr->next = curr1;
            ptr = ptr->next;
            curr1 = curr1->next;
        }
    }
    else
    {
        while (curr2 != NULL)
        {
            ptr->next = curr2;
            ptr = ptr->next;
            curr2 = curr2->next;
        }
    }
    return dummyNode->next;
}

Node *recursiveMerging(Node *head1, Node *head2)
{
    Node *result;
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head2;
    }
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = recursiveMerging(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = recursiveMerging(head1, head2->next);
    }
    return result;
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
    Node *head3 = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 7);
    insertAtTail(head2, 2);
    insertAtTail(head2, 3);
    insertAtTail(head2, 6);
    display(head1);
    display(head2);
    // head3 = mergingTwoList(head1, head2);
    head3 = recursiveMerging(head1, head2);
    display(head3);
}