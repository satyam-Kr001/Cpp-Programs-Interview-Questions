#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *node = new Node(val);
    if (head == NULL)
    {
        head = node;
        return;
    }
    node->next = head;
    head->prev = node;

    head = node;
}

void insertAtEnd(Node *&head, int val)
{
    Node *node = new Node(val);
    Node *curr = head;
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = node;
    node->prev = curr;
}

void deletion(Node *&head, int pos)
{
    if (pos == 1)
    {
        Node *prevHead = head;
        head = head->next;
        head->prev = NULL;
        free(prevHead);
        return;
    }

    Node *curr = head;
    int count = 1;
    while (curr != NULL and count != pos)
    {
        curr = curr->next;
        count++;
    }
    curr->prev->next = curr->next;
    if (curr->next != NULL)
        curr->next->prev = curr->prev;
    free(curr);
}

void display(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " <-> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    insertAtHead(head, 7);
    display(head);
    deletion(head, 1);
    display(head);
}