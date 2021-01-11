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
    int ret = 0;

    void getMaxDepth(TreeNode *root, int depth)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            if (ret < depth)
            {
                ret = depth;
            }
            return;
        }

        if (root->left != nullptr)
        {
            getMaxDepth(root->left, depth + 1);
        }
        if (root->right != nullptr)
        {
            getMaxDepth(root->right, depth + 1);
        }
    }

    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }

        getMaxDepth(root, 1);
        return ret;
    }
};