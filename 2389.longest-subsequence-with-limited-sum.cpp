/*
 * @lc app=leetcode id=2389 lang=cpp
 *
 * [2389] Longest Subsequence With Limited Sum
 */

// @lc code=start

#define OPTIMIZIED
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        /**
         * @brief 
         * Solution: Prefix Sum and Search
         * Time Complexity: O(nlogn + n*m)
         * Accepted: 44ms(33.57%), 13.8MB(37.34%)
         * 1. Sort the nums and record the Prefix Sum into tmp.
         * 2. Search the queries from tmp list.
         * 
         * Optimizied:
         * 1. Binary Search (upper_bound): This function will return
         *    the first address of the bigger or equal number of the
         *    target in the sorted list.
         *    upper_bound(sorted.begin(), sorted.end(), target)
         * 
         *    Time Complexity: O(nlogn + mlogn)
         *    Accepted: 19ms(75.38%), 13.8MB(37.34%)
         * 
         */
        vector<int> ans(queries.size(), 0);
        vector<int> tmp(nums.size(), 0);

        sort(nums.begin(), nums.end()); // O(nlogn)

        tmp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){ // O(n)
            tmp[i] = tmp[i-1] + nums[i];
            //cout << tmp[i] << endl;
        }

#ifndef OPTIMIZIED // O(n*m)
        for(int i = 0; i < queries.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if(queries[i] < tmp[j]){
                    ans[i] = j;
                    break;
                }else if(j == nums.size()-1){
                    ans[i] = j+1;
                    break;
                }
            }
        }
#else   // O(mlogn)
        for(int i = 0; i < queries.size(); i++){
            int index = 0;
            index = (upper_bound(tmp.begin(), tmp.end(), queries[i])-tmp.begin());
            ans[i] = index;
        }
#endif

        return ans;
    }
};
// @lc code=end

