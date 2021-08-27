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

void insertKNodesAtBegining(Node *&head, int pos, int n)
{
    int startPos = n - pos;
    int count = 1;
    Node *curr = head;
    Node *nextPtr = head->next;
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (count != startPos)
        {
            curr = curr->next;
            nextPtr = nextPtr->next;
            count++;
        }
        temp = temp->next;
    }
    curr->next = NULL;
    temp->next = head;
    head = nextPtr;
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
    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);
    insertKNodesAtBegining(head, 4, 6);
    display(head);
}