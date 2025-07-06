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

Node* createLL()
{
    int data;
    Node* head = nullptr;
    Node* tail = nullptr;

    cin >> data;
    while (data != -1) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
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

int main()
{
    cout << "Enter values to store in Linked List (enter -1 to stop): " << endl;
    Node* head = createLL();

    cout << "Created List is: ";
    printLL(head);

    return 0;
}
