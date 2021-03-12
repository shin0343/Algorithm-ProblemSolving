/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        // count by edges but not by nodes
        int option1 = heightOfTree(root->left) + heightOfTree(root->right);
        int option2 = diameterOfBinaryTree(root->left);
        int option3 = diameterOfBinaryTree(root->right);

        return max(option1, max(option2, option3));
    }

    int heightOfTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
    }
};