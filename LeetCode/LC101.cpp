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
    bool isSymmetric(TreeNode *root)
    {
        bool ans = true;
        queue<TreeNode *> lq, rq;

        lq.push(root->left);
        rq.push(root->right);

        while (!lq.empty() || !rq.empty())
        {
            TreeNode *ln = lq.front();
            TreeNode *rn = rq.front();
            lq.pop();
            rq.pop();

            if (ln == nullptr && rn == nullptr)
                continue;

            if ((ln == nullptr && rn != nullptr) || (rn == nullptr && ln != nullptr))
            {
                ans = false;
                break;
            }

            if (ln->val != rn->val)
            {
                ans = false;
                break;
            }

            lq.push(ln->left);
            lq.push(ln->right);
            rq.push(rn->right);
            rq.push(rn->left);
        }

        if ((lq.empty() && !rq.empty()) || (!lq.empty() && rq.empty()))
            ans = false;

        return ans;
    }
};