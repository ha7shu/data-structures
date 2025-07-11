#include <iostream>
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

// Sample static tree for testing:
//         1
//       /   \
//      2     3
//     / \
//    4   5
TreeNode* createSampleTree()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

// Inorder DFS (Left -> Root -> Right)
void inorder(TreeNode* root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder DFS (Root -> Left -> Right)
void preorder(TreeNode* root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder DFS (Left -> Right -> Root)
void postorder(TreeNode* root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    TreeNode* root = createSampleTree();

    cout << "Inorder: ";
    inorder(root);
    cout << "\n";

    cout << "Preorder: ";
    preorder(root);
    cout << "\n";

    cout << "Postorder: ";
    postorder(root);
    cout << "\n";

    return 0;
}
