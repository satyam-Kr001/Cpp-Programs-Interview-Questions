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
void insertAtBegin(Node *&head, int data)
{
    Node *newHead = new Node(data);
    newHead->next = head;
    head = newHead;

    // return head;
}

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

bool search(Node *head, int ele)
{
    while (head != NULL)
    {
        if (head->data == ele)
            return true;
        head = head->next;
    }
    return false;
}

void reverseList(Node *&head)
{
    Node *currPtr = head;
    Node *prev = NULL;
    Node *nextPtr;
    while (currPtr != NULL)
    {
        nextPtr = currPtr->next;
        currPtr->next = prev;
        prev = currPtr;
        currPtr = nextPtr;
    }
    head = prev;
}

Node *reverseListRecursive(Node *&head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    Node *newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

Node *reverseKNodesList(Node *&head, int k)
{
    int count = 0;
    Node *nextPtr;
    Node *currPtr = head;
    Node *prevPtr = NULL;
    while (currPtr != NULL and count < k)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
        count++;
    }
    if (nextPtr != NULL)
    {
        head->next = reverseKNodesList(nextPtr, k);
    }
    return prevPtr;
}

void makeCycle(Node *&head, int pos)
{
    Node *curr = head;
    Node *startNode;

    int count = 1;
    while (curr->next != NULL)
    {
        if (count == pos)
        {
            startNode = curr;
        }
        curr = curr->next;
        count++;
    }
    curr->next = startNode;
}

void cycleDetection(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "Cycle detected" << endl;
            return;
        }
    }
    cout << "Not detected" << endl;
}

void cycleRemoval(Node *&head)
{
    // Node *slow = head;
    // Node *fast = head;
    // do
    // {
    //     slow = slow->next;
    //     fast = fast->next->next;
    // } while (fast != slow);

    // fast = head;
    // while (fast->next != slow->next)
    // {
    //     fast = fast->next;
    //     slow = slow->next;
    // }
    // slow->next = NULL;

    unordered_map<Node *, int> m;
    Node *prev = NULL;
    while (head != NULL)
    {
        if (!m[head])
        {
            m[head] = 1;
        }
        else
        {
            prev->next = NULL;
            break;
        }
        prev = head;
        head = head->next;
    }
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

void deleteNode(Node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        return;
    }

    Node *curr = head;
    if (head->data == val)
    {
        curr = head;
        head = head->next;
        free(curr);
    }
    else
    {
        while (curr->next->data != val)
        {
            curr = curr->next;
        }
        // Node* toDelete = curr->next;
        curr->next = curr->next->next;
        free(curr->next);
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
    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    // makeCycle(head, 3);
    // display(head);
    // cycleDetection(head);
    // cycleRemoval(head);
    // cycleDetection(head);
    // display(head);
    // int res = search(head, 5);
    // deleteNode(head, 4);
    Node *newHead = reverseListRecursive(head);
    Node *newHead = reverseKNodesList(head, 2);
    display(newHead);
}