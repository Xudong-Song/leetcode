/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    /**
     * @brief Combination -> C(a,b)
     * 
     * @param a 
     * @param b 
     * @return int
     */
    int C(int a, int b){
        if(b == 0){ return 1; }
        
        long int a_tmp = 1;
        int b_tmp = 1;

        for(int i = 1; i <= b; i++){
            b_tmp *= i;
            a_tmp *= (a-i+1);

            if(a_tmp % b_tmp == 0) {
                a_tmp /= b_tmp;
                b_tmp = 1;
            }
        }

        return a_tmp/b_tmp;
    }
    int climbStairs(int n) {
        /**
         * @brief 
         * Solution: Math, Combination, C(n,m)
         * Time Complexity: O(n)
         * Accepted: 0ms(100%), 6MB(60.53%)
         * 1. The answer is C(n,0)+C(n-1,1)+C(n-2,2)...
         * 2. The number should be very big, therefore, we must divide them 
         *    if the number can be evenly divisible.
         * 
         */
        int ans = 0;
        int m = 0;

        while(n >= m){
            ans += C(n, m);
            n--;
            m++;
        }
        
        return ans;
    }
};
// @lc code=end

