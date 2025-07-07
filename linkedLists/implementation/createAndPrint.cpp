#include <iostream>
#include <vector>
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

Node* createLLFromInput()
{
    int data;
    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter values (-1 to stop): ";
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

Node* createLLFromArray(int arr[], int n)
{
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

Node* createLLFromVector(const vector<int>& vec)
{
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int val : vec) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
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
    Node* head = nullptr;
    int choice;

    cout << "Choose method to create Linked List:" << endl;
    cout << "1. Manual Input" << endl;
    cout << "2. From Array" << endl;
    cout << "3. From Vector" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        head = createLLFromInput();
        break;

    case 2: {
        int n;
        cout << "Enter size of array: ";
        cin >> n;
        int* arr = new int[n];
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        head = createLLFromArray(arr, n);
        delete[] arr;
        break;
    }

    case 3: {
        int n;
        cout << "Enter number of elements: ";
        cin >> n;
        vector<int> vec(n);
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; ++i)
            cin >> vec[i];
        head = createLLFromVector(vec);
        break;
    }

    default:
        cout << "Invalid choice!" << endl;
        return 1;
    }

    cout << "Created List is: ";
    printLL(head);

    return 0;
}
