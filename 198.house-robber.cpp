/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        /**
         * @brief 
         * Solution: Buttom-Up / Top-Down
         * Time Complexity: O(n)
         * Accepted: 0ms(100%), 7.6MB(95.23%)
         * 
         */
        if(nums.size()==2) return nums[0]>nums[1]?nums[0]:nums[1];
        else if(nums.size()==1) return nums[0];
        
        nums[2] += nums[0];
        for(int i = 3; i < nums.size(); i++)
            nums[i] += nums[i-2]>nums[i-3]?nums[i-2]:nums[i-3];
        
        return nums[nums.size()-1]>nums[nums.size()-2]?
               nums[nums.size()-1]:nums[nums.size()-2];
    }
};
// @lc code=end

