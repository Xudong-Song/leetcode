/*
 * @lc app=leetcode id=2443 lang=cpp
 *
 * [2443] Sum of Number and Its Reverse
 */

// @lc code=start
class Solution {
public:
    int reverse(int i) {
        int tmp = 0;
        while(i > 0){
            tmp = tmp*10 + i%10;
            i/=10;
        }
        return tmp;
    }
    bool sumOfNumberAndReverse(int num) {
        /**
         * @brief 
         * Solution:
         * Time Complexity: O(n*m) which n = num, m = log10(i)
         * Accepted: 63ms(77.7%), 5.8MB(75.21%)
         * 1. sum the number with its reverse.
         * 
         */
        for(int i = 0; i <= num; i++) {
            int rev = reverse(i);
            
            if(num-i == rev) {
                // cout << i << "," << rev;
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

