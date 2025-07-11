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

// BFS traversal (Level Order)
void levelOrder(TreeNode* root)
{
    if (!root)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
}

int main()
{
    TreeNode* root = createSampleTree();

    cout << "Level Order (BFS): ";
    levelOrder(root);
    cout << endl;

    return 0;
}
