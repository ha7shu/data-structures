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

// Inorder traversal to verify tree
void inorder(TreeNode* root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Find the deepest and rightmost node
TreeNode* getDeepestNode(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* temp = nullptr;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return temp;
}

// Delete the deepest node
void deleteDeepest(TreeNode* root, TreeNode* dNode)
{
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr == dNode) {
            delete curr;
            return;
        }
        if (curr->right) {
            if (curr->right == dNode) {
                delete curr->right;
                curr->right = nullptr;
                return;
            } else {
                q.push(curr->right);
            }
        }
        if (curr->left) {
            if (curr->left == dNode) {
                delete curr->left;
                curr->left = nullptr;
                return;
            } else {
                q.push(curr->left);
            }
        }
    }
}

// Delete node with given key
TreeNode* deleteNode(TreeNode* root, int key)
{
    if (!root)
        return nullptr;

    if (!root->left && !root->right) {
        if (root->data == key) {
            delete root;
            return nullptr;
        } else {
            return root;
        }
    }

    TreeNode* keyNode = nullptr;
    TreeNode* temp;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->data == key)
            keyNode = temp;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }

    if (keyNode) {
        TreeNode* deepest = getDeepestNode(root);
        keyNode->data = deepest->data;
        deleteDeepest(root, deepest);
    }

    return root;
}

int main()
{
    // Sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    int key;
    cout << "Enter value to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
