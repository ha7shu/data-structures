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

Node* insertAtBeginning(Node* head, int val)
{
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;
}

Node* insertAtEnd(Node* head, int val)
{
    Node* newNode = new Node(val);
    if (!head)
        return newNode;

    Node* curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}

Node* insertAtPosition(Node* head, int pos, int val)
{
    if (pos == 0) {
        return insertAtBeginning(head, val);
    }

    Node* current = head;
    for (int i = 0; current != nullptr && i < pos - 1; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position " << pos << " out of bounds.\n";
        return head;
    }

    Node* newNode = new Node(val);
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

int main()
{
    Node* head = createSampleLL();

    cout << "Original List: " << endl;
    printLL(head);

    // Insert at beginning
    int valAtBeginning = 50;
    head = insertAtBeginning(head, valAtBeginning);
    cout << "Updated List after insertion at beginning: " << endl;
    printLL(head);

    // Insert at end
    int valAtEnd = 400;
    head = insertAtEnd(head, valAtEnd);
    cout << "Updated List after insertion at end: " << endl;
    printLL(head);

    // Insert at position
    int pos = 2; // 0-based index
    int valAtPos = 150;
    head = insertAtPosition(head, pos, valAtPos);
    cout << "Updated List after insertion at position " << pos << ": " << endl;
    printLL(head);

    return 0;
}
