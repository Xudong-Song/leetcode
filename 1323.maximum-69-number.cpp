/*
 * @lc app=leetcode id=1323 lang=cpp
 *
 * [1323] Maximum 69 Number
 */

// @lc code=start
class Solution {
public:
    int maximum69Number (int num) {
        
        int n[4] = {};
        int i = 3;
        while(num > 0){
            n[i] = num%10;
            num /= 10;
            // cout << n[i] << endl;
            i--;
        }

        for(int j = 0; j < 4; j++){
            if(n[j] == 6) {
                n[j] = 9;
                break;
            }
        }

        int ans = 0;
        int digit = 1;
        for(int k = 3; k >= 0; k--){
            ans += n[k]*digit;
            digit *= 10;
        }

        return ans;
    }   
};
// @lc code=end

