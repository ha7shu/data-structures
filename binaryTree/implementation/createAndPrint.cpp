#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

// 1. Static Manual Construction
TreeNode* createTreeStatic()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

// 2. Level Order Input (-1 for NULL)
TreeNode* createTreeLevelOrder()
{
    int val;
    cin >> val;
    if (val == -1)
        return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new TreeNode(leftVal);
            q.push(curr->left);
        }

        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new TreeNode(rightVal);
            q.push(curr->right);
        }
    }

    return root;
}

// 3. Create from Array (Complete Binary Tree)
TreeNode* createTreeFromArray(const vector<int>& arr, int i = 0)
{
    if (i >= arr.size() || arr[i] == -1)
        return nullptr;
    TreeNode* root = new TreeNode(arr[i]);
    root->left = createTreeFromArray(arr, 2 * i + 1);
    root->right = createTreeFromArray(arr, 2 * i + 2);
    return root;
}

// 4. Recursive Preorder Input ("true"/"false")
TreeNode* createTreeRecursivePreorder()
{
    int val;
    cin >> val;
    TreeNode* root = new TreeNode(val);

    string left, right;
    cin >> left;
    if (left == "true")
        root->left = createTreeRecursivePreorder();

    cin >> right;
    if (right == "true")
        root->right = createTreeRecursivePreorder();

    return root;
}

// Inorder Traversal
void inorder(TreeNode* root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    TreeNode* root = nullptr;
    int choice;

    cout << "Choose method to create Binary Tree:\n";
    cout << "1. Static\n2. Level Order\n3. From Array\n4. Recursive Preorder\n";
    cin >> choice;

    switch (choice) {
    case 1:
        root = createTreeStatic();
        break;
    case 2:
        cout << "Enter root, then children (-1 for NULL): ";
        root = createTreeLevelOrder();
        break;
    case 3: {
        int n;
        cout << "Enter number of elements: ";
        cin >> n;
        vector<int> arr(n);
        for (int& x : arr)
            cin >> x;
        root = createTreeFromArray(arr);
        break;
    }
    case 4:
        cout << "Enter values: <val> <\"true\"/\"false\"> for left/right:\n";
        root = createTreeRecursivePreorder();
        break;
    default:
        cout << "Invalid choice.\n";
        return 0;
    }

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\n";
    return 0;
}
