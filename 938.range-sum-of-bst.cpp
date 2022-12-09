/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
    void get_value(TreeNode* root, int& ans, int low, int high){
        if(root){
            get_value(root->left, ans, low, high);
            if(root->val <= high && root->val >= low) ans += root->val;
            // cout << root->val << ",";
            get_value(root->right, ans, low, high);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        get_value(root, ans, low, high);
        return ans;
    }
};
// @lc code=end

