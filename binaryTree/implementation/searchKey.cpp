#include <iostream>
#include <queue>
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

// 1. Create a sample static tree
TreeNode* createTreeStatic()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

// 2. Print using DFS (inorder traversal)
void printInorder(TreeNode* root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// 3. DFS-based Search
bool searchDFS(TreeNode* root, int key)
{
    if (!root)
        return false;
    if (root->data == key)
        return true;
    return searchDFS(root->left, key) || searchDFS(root->right, key);
}

// 4. BFS-based Search
bool searchBFS(TreeNode* root, int key)
{
    if (!root)
        return false;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr->data == key)
            return true;
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    return false;
}

int main()
{
    // Step 1: Create the tree
    TreeNode* root = createTreeStatic();

    // Step 2: Print the tree (Inorder)
    cout << "Inorder Traversal of Binary Tree: ";
    printInorder(root);
    cout << endl;

    // Step 3: Input key to search
    int key;
    cout << "Enter value to search: ";
    cin >> key;

    // Step 4: Search using DFS
    cout << "\nSearching using DFS: ";
    if (searchDFS(root, key))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    // Step 5: Search using BFS
    cout << "Searching using BFS: ";
    if (searchBFS(root, key))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}
