/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
     * @brief Get the maxinum number of l & r
     * 
     * @param l left node
     * @param r right node
     * @return int 
     */
    int max(TreeNode* l, TreeNode* r) {
        if(l && r) return r->val>l->val ? r->val:l->val;
        else if(l && !r) return l->val;
        else if(!l && r) return r->val;
        else return 0;
    }

    /**
     * @brief Use "max" function to get the path value of every node, then 
     *        record the maxinum number of all path.
     * 
     * @param root 
     * @param ans 
     */
    void DFS(TreeNode* root, int& ans) {
        if(!root) return ;

        // DFS, we should start from the buttom of the tree.
        DFS(root->left, ans);
        DFS(root->right, ans);

        // Maxinum number of All nodes.
        int tmp = root->val;
        if(root->right) tmp += root->right->val>0 ? root->right->val:0;
        if(root->left) tmp += root->left->val>0 ? root->left->val:0;
        if(tmp > ans) ans = tmp;
        
        // Cal the path of All nodes.
        int tmp_root = max(root->right, root->left);
        if(tmp_root > 0)
            root->val += tmp_root;
    }

    int maxPathSum(TreeNode* root) {
        /**
         * @brief 
         * Solution: DFS, Buttom-UP
         * Time Complexity: O(n)
         * Accepted: 24ms(93.94%), 27.8MB(31.84%)
         * 1. All node add as max number of their left and right path value.
         * 2. Remenber, we should not add any minus path value.
         * 3. At every node, get their maxinum path, and record it as answer.
         * 
         */
        int ans = -1001;
        DFS(root, ans);
        return ans;
    }
};
// @lc code=end

