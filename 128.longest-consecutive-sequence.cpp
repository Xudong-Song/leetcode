/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        /**
         * @brief Use Set
         * 
         * Set introduction:
         * 1. Data is automatically sorted
         * 2. Storage data not repeat
         * 3. "count" function only need O(log N)
         */

        int ans = 0;
        set<int> tmp;

        // insert all the data into "set" data structure.
        for(int i = 0; i < nums.size(); i++)
        {
            tmp.insert(nums[i]);
        }

        
        for(auto data : tmp)
        {
            // at least one element exist.
            int count = 1;

            // return 1 if data+1 is exist, otherwise, return 0.
            while(tmp.count(data+1))
            {
                // if find one, record it.
                count++; 
                
                // move to next data.
                data = data+1; 

                // remove the previous data, avoid repetitive operations
                tmp.erase(data); 
            }

            // find the maximum consecutive sequence
            ans = max(count, ans);
        }

        return ans;
    }
};
// @lc code=end

