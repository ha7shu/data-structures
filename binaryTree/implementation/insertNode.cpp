#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

// Insert node at first available position using level order
void insertNode(TreeNode* root, int val)
{
    if (!root)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        // insert in left if empty
        if (!curr->left) {
            curr->left = new TreeNode(val);
            return;
        } else {
            q.push(curr->left);
        }

        // insert in right if empty
        if (!curr->right) {
            curr->right = new TreeNode(val);
            return;
        } else {
            q.push(curr->right);
        }
    }
}

// Print tree in level order (BFS)
void levelOrder(TreeNode* root)
{
    if (!root)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int main()
{
    // Create initial tree manually
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    cout << "Initial Tree (Level Order): ";
    levelOrder(root);
    cout << endl;

    // Insert a new node
    int newVal;
    cout << "Enter value to insert: ";
    cin >> newVal;

    insertNode(root, newVal);

    cout << "Tree After Insertion: ";
    levelOrder(root);
    cout << endl;

    return 0;
}
