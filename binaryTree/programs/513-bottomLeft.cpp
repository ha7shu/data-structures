/* 513. Find Bottom Left Tree Value
 *
 * Given the root of a binary tree, return the leftmost value in the last row of the tree.
 *
 * Example 1:
 *
 * Input: root = [2,1,3]
 * Output: 1
 *
 * Example 2:
 *
 * Input: root = [1,2,3,4,null,5,6,null,null,7]
 * Output: 7
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);

        int leftMax = root->val;

        while (!q.empty()) {
            int n = q.size();
            leftMax = q.front()->val;

            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }
        return leftMax;
    }
};
