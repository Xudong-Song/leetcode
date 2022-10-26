/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 */

// @lc code=start
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
    void sum(TreeNode* root, int path, int &ans) {

        path *= 10;
        path += root->val;

        if(root->left)
            sum(root->left, path, ans);
        if(root->right)
            sum(root->right, path, ans);
        if(!root->left && !root->right)
            ans += path;
    }

    int sumNumbers(TreeNode* root) {
        int path = 0;
        int ans = 0;

        sum(root, path, ans);
        
        return ans;
    }
};
// @lc code=end

