/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
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
#define MAX_INT 2147483647
class Solution {
public:
    void solution(TreeNode* root, int& max, int& min, int& ans){
        int tmp_max = max;
        int tmp_min = min;
        if(root->left){
            if(root->val > root->left->val){
                if(max < root->val) max = root->val;
                if(min > root->left->val) min = root->left->val;
            }else{
                if(max < root->left->val) max = root->left->val;
                if(min > root->val) min = root->val;
            }
            if(ans < max-min) ans = max-min;
            //cout << max << "," << min << "," << ans << "\n";
            solution(root->left, max, min, ans);
        }
        max = tmp_max;
        min = tmp_min;
        if(root->right){
            if(root->val > root->right->val){
                if(max < root->val) max = root->val;
                if(min > root->right->val) min = root->right->val;
            }else{
                if(max < root->right->val) max = root->right->val;
                if(min > root->val) min = root->val;
            }
            if(ans < max-min) ans = max-min;
            //cout << max << "," << min << "," << ans << "\n";
            solution(root->right, max, min, ans);
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        /**
         * @brief 
         * Solution: DFS, Get Max and Min value at both right and left sub tree, 
         *           then get the difference of them as answer.
         * Accepted: 10ms(56.52%), 9.9MB(39.02%)
         */

        int max = 0, min = MAX_INT, ans = 0;
        solution(root, max, min, ans);
        return ans;
    }
};
// @lc code=end

