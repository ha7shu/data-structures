#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val)
        : data(val)
        , next(nullptr)
    {
    }
};

Node* createSampleLL()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    return head;
}

Node* findTail(Node* head)
{
    if (!head)
        return nullptr;
    Node* curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    return curr;
}

int findValue(Node* head, int val)
{
    int index = 0;
    Node* curr = head;
    while (curr) {
        if (curr->data == val)
            return index;
        curr = curr->next;
        index++;
    }
    return -1;
}

int main()
{
    Node* head = createSampleLL();

    cout << "Linked List: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    Node* tail = findTail(head);
    if (tail)
        cout << "Tail of the linked list is: " << tail->data << endl;
    else
        cout << "The list is empty." << endl;

    int target = 30;
    int index = findValue(head, target);
    if (index != -1)
        cout << "Value " << target << " found at index: " << index << endl;
    else
        cout << "Value " << target << " not found in the list." << endl;

    return 0;
}
