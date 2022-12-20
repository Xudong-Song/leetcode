/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        /**
         * @brief 
         * Solution: Stack, Hash-Table
         * Time Complexity: O(n^2)
         * Accepted: 254ms(67.96%), 103MB(49.03%)
         * 1. Push the index into the stack every loop.
         * 2. If there is a bigger number, pop it and record the diff between
         *    stack top and index now.
         * 
         */
        vector<int> ans(t.size(), 0);
        stack<int> s;
        s.push(0);
        for(int i = 1; i < t.size(); i++){
            while(t[i] > t[s.top()]){
                ans[s.top()] = i-s.top();
                s.pop();
                if(s.empty()) break;
            }
            s.push(i);
        }
        
        return ans;
    }
};
// @lc code=end

