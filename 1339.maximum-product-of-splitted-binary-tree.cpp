/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
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

    /**
     * @brief 1. Get the Total value of all node.
     *        2. Every node add as their sub tree sum.
     * @param root 
     * @param sum 
     */
    void Get_SUM(TreeNode* root, long long int& sum) {
        if(!root) return ;
        Get_SUM(root->left, sum);
        Get_SUM(root->right, sum);
        sum += root->val;
        if(root->left) root->val += root->left->val;
        if(root->right) root->val += root->right->val;
        //cout << root->val << ",";
    }

    /**
     * @brief Check all possible number, and record the maxinum one.
     * 
     * @param root 
     * @param sum 
     * @param ans 
     */
    void DFS(TreeNode* root, long long int& sum, long long int& ans) {
        if(!root) return ;
        DFS(root->left, sum, ans);
        DFS(root->right, sum, ans);

        long long int tmp = ((sum-root->val)*root->val);
        if(tmp > ans) ans = tmp;
        //cout << tmp << ",";
    }

    int maxProduct(TreeNode* root) {
        /**
         * @brief 
         * Solution: DFS
         * Time Complexity: O(n)
         * Accepted: 138ms(88.08%), 78.8MB(39.39%)
         * 1. Get the Sum of all node.
         * 2. Because we can only split once, the split side must be a sub-tree
         *    of tree. Therefore, the we should add all nodes as their 
         *    sub-tree's sum.
         * 3. Calculate all possible combination, and record the maxinum one.
         * 
         */
        long long int sum = 0;
        long long int ans = 0;
        Get_SUM(root, sum);
        DFS(root, sum, ans);
        return ans % 1000000007;
    }
};
// @lc code=end

