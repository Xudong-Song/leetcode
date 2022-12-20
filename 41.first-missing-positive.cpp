/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
private:
    int abs(int n){
        return n>0 ? (n-0):(0-n);
    }

public:
    int firstMissingPositive(vector<int>& nums) {
        /**
         * @brief 
         * Solution1: Use n:nums as index.
         *            The ideal array of nums is 1~n, if we find 
         *            a number which is bigger than n, the number
         *            must not be our answer.
         *            Therefore, we can just look up the number < n,
         *            and mark it as a specific number.
         * Time Complexity: O(n)
         * Space Complexity: O(1)
         * Accepted: 50ms(91.4%), 31.5MB(48.12%)
         * 1. for(n:nums), goto nums[n] and turn the number into a 
         *    specific number.
         * 2. After step1, for(n:nums), if n is not the specific 
         *    number(n*=-1), return it as answer.
         * 3. Because the range of the possible number is the whole
         *    integer, we should move some space for the specific 
         *    number.
         * 4. If the array has 1~n, return n+1
         * 
         */
        int MAX_INT = nums.size()+1;

        for(auto& n:nums)
            if(n <= 0) n = MAX_INT;

        /*for(auto n:nums)
            cout << n << ",";
        cout << endl;*/

        for(auto n:nums)
            if(abs(n) < MAX_INT && abs(n) > 0 && nums[abs(n)-1] > 0)
                nums[abs(n)-1] *= -1;
            
        /*for(auto n:nums)
            cout << n << ",";*/

        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0)
                return i+1;


        return MAX_INT;
    }
};
// @lc code=end

