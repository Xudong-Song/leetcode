/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
    void get_leaf(TreeNode* root, vector<int>& leaf) {
        if(root->left || root->right){
            if(root->left) get_leaf(root->left, leaf);
            if(root->right) get_leaf(root->right, leaf);
        }else leaf.push_back(root->val);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;

        get_leaf(root1, leaf1);
        get_leaf(root2, leaf2);

        if(leaf1 == leaf2) return true;
        else return false;
    }
};
// @lc code=end

