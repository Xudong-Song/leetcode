/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /**
         * @brief 
         * Solution: Time Complexity: O(n^2)
         *           Accepted, 74ms(5.11%), 15.6MB(75.75%)
         * 1. Add each of two numbers, and check if the answer is equal to target.
         * 2. Beacuse it is a sorted array, we should not double check the same item twice.
         *    Therefore, when we meet the same item, skip it.
         * 
         */
        vector<int> ans;
        for(int i = 0; i < numbers.size(); i++){
            for(int j = i+1; j < numbers.size(); j++){
                if(numbers[i]+numbers[j] == target){
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                }
                if(numbers[i] == numbers[j]) break;
            }
        }
        return ans;
    }
};
// @lc code=end

