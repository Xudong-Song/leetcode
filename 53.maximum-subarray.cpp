/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = -999999;
        int current = -999999;
        for(int i = 0; i < nums.size(); i++){
            if(current <= 0 && current < nums[i]){
                current = nums[i];
            }
            else{
                current+=nums[i];
            }
            if(max <= current){
                max = current;
            }
        }
        return max;
    }
};
// @lc code=end

