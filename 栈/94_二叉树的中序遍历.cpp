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

// 参考答案 
class Solution {
public:
    void traversal(TreeNode* root, vector<int>& res) // 加上引用 &才能改变 vector<int> 的值
    {
        if (!root) return;
        traversal(root->left, res);
        res.push_back(root->val);
        traversal(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);

        return result;
    }
};
