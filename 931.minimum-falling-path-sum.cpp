/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
#define MAX_INT 2147483647
class Solution {
public:
    int min(int n1, int n2, int n3){
        int n = n1<n2 ? n1:n2;
        return n<n3 ? n:n3;
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        /**
         * @brief 
         * Solution: Buttom-Up (Greedy)
         * Time Complexity = O(nm)
         * 1. All point += the min number of next step.
         * ex: 
         *  Step1. 
         *      [2,1,3]
         *      [6,5,4]
         *      [7,8,9]
         *  Step2.
         *      [2,             1,           3             ]
         *      [6+min(MAX,7,8),5+min(7,8,9),4+min(8,9,MAX)]
         *      [7,             8,           9             ]
         *  Step3.
         *      [2+min(MAX,13,12),1+min(13,12,12),3+min(12,12,MAX)]
         *      [13,              12,             12              ]
         *      [7,               8,              9               ]
         * 
         * 2. Sort the first row of matrix, return the first number.
         *    -> Accepted: 19ms(81.48%), 9.7MB(99.78%)
         * 
         * 3. Use "*min_element" instead of "Sort" might be faster.
         *    -> Accepted: 8ms(99.50%), 9.8MB(95.85%)
         * 
         */
        int ans = 0;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < m; j++){
                int n1 = (j-1 >= 0) ? mat[i+1][j-1]:MAX_INT;
                int n2 = mat[i+1][j];
                int n3 = (j+1 < m) ? mat[i+1][j+1]:MAX_INT;
                mat[i][j] += min(n1,n2,n3);
            }
        }
        // sort(mat[0].begin(), mat[0].end());
        // return mat[0][0];
        return *min_element(mat[0].begin(), mat[0].end());
    }
};
// @lc code=end

