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

// 递归
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);

        return res;
    }

    void postorder(TreeNode* root, vector<int>& res)
    {
        if (!root) return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
};

//迭代 参考答案， 前序遍历改变 left和right 的顺序然后 reverse 得到后序遍历

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};

        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty())
        {
            auto t = stk.top();
            stk.pop();
            res.push_back(t->val);
            if (t->left) stk.push(t->left);
            if (t->right) stk.push(t->right);  
        }
        reverse(res.begin(), res.end());


        return res;
    }
};
