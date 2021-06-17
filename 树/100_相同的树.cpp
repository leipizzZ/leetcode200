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
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q) return true;
        if (!p || !q) return false;

        stack<TreeNode*> stkp;
        stack<TreeNode*> stkq;

        while (p && q || !stkp.empty() && !stkq.empty())
        {
            if (p && q)
            {
                if (p->val != q->val) return false;
                else 
                {
                    stkp.push(p);
                    stkq.push(q);

                    q = q->left;
                    p = p->left;
                    if (!q && p || q && !p)
                        return false;
                }
            }
            else 
            {
                p = stkp.top();
                q = stkq.top();
                stkp.pop();
                stkq.pop();

                q = q->right;
                p = p->right;
                if (!q && p || q && !p)
                        return false;
            }
        }
        return true;
    }
};
