/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 */

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(i+1 >= matrix.size() || j+1 >= matrix[0].size()) continue;
                if(matrix[i][j] != matrix[i+1][j+1]) return false;
            }
        }
        return true;
    }
};
// @lc code=end

