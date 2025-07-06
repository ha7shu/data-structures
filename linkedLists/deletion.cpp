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
    Node* head = new Node(100);
    head->next = new Node(200);
    head->next->next = new Node(300);
    head->next->next->next = new Node(400);
    head->next->next->next->next = new Node(500);
    return head;
}

void printLL(Node* head)
{
    Node* curr = head;
    while (curr) {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int deleteFromBeginning(Node*& head)
{
    if (!head) {
        cout << "List is empty.\n";
        return -1;
    }
    int val = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    return val;
}

int deleteFromEnd(Node*& head)
{
    if (!head) {
        cout << "List is empty.\n";
        return -1;
    }
    if (!head->next) {
        int val = head->data;
        delete head;
        head = nullptr;
        return val;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    int val = temp->next->data;
    delete temp->next;
    temp->next = nullptr;
    return val;
}

int deleteFromPosition(Node*& head, int pos)
{
    if (!head) {
        cout << "List is empty.\n";
        return -1;
    }
    if (pos == 0) {
        return deleteFromBeginning(head);
    }

    Node* current = head;
    for (int i = 0; current != nullptr && i < pos - 1; ++i) {
        current = current->next;
    }

    if (!current || !current->next) {
        cout << "Position out of bounds.\n";
        return -1;
    }

    Node* temp = current->next;
    int val = temp->data;
    current->next = temp->next;
    delete temp;
    return val;
}

int main()
{
    Node* head = createSampleLL();
    cout << "Original List:\n";
    printLL(head);

    int deletedVal;

    deletedVal = deleteFromBeginning(head);
    cout << "Deleted from beginning: " << deletedVal << endl;
    printLL(head);

    deletedVal = deleteFromEnd(head);
    cout << "Deleted from end: " << deletedVal << endl;
    printLL(head);

    int pos = 1;
    deletedVal = deleteFromPosition(head, pos);
    cout << "Deleted from position " << pos << ": " << deletedVal << endl;
    printLL(head);

    return 0;
}
