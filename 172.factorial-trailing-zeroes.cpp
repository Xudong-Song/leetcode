/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        /**
         * @brief trailing(在後面、尾隨)
         * 
         * Solution: 0! = 1, don't worry. 
         *           Time Complexity: O(logˇ5N)
         *           Accetped, 0ms(100%), 6MB(29.03%)
         * 1. All 0 trailing should comes from 10.
         * 2. Therefore, we can count how many 5 we has meet.
         *    How about 2? The number we meet 2 is far more than we meet 5.
         * 3. Not enough, for example, when we meet 25*4, we will get 100.
         *    Therefore, when we meet 5^2 * 2^2, we will get another 0 behind.
         *    So on and so forth, 5^3 * 2^3, 5^4 * 2^4 ...
         * 
         */
        int ans = 0;
        for(int i = 5; i <= n; i*=5) ans += n/i;
        return ans;
    }
};
// @lc code=end

