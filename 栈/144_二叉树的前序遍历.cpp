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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);

        return res;
    }

    void preorder(TreeNode* root, vector<int>& res)
    {
        if (!root) return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
};

//迭代 参考答案
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};//空节点不入栈
        vector<int> res;
        stack<TreeNode*> stk;

        stk.push(root);
        while(!stk.empty())
        {
            auto t = stk.top();
            res.push_back(t->val);
            stk.pop();
            if (t->right) stk.push(t->right); //空节点不入栈
            if (t->left) stk.push(t->left);
        }

        return res;
    }
};
