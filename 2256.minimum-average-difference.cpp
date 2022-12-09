/*
 * @lc app=leetcode id=2256 lang=cpp
 *
 * [2256] Minimum Average Difference
 */

// @lc code=start

//#define SOLUTION_1 // Time Limit Exceeded: 60/78 cases passed (N/A)
#define SOLUTION_2 // Accepted: 139ms(84.00%), 78.3MB(71.05%)
#define MAX_INT 2147483647

class Solution {
public:
#ifdef SOLUTION_1
    int solution1(vector<int>& nums, int index);
#endif
    int minimumAverageDifference(vector<int>& nums) {
        /**
         * @brief 
         * Solution1: Use the function that given by the example.
         * Time Complexity: O(n^2)
         * Time Limit Exceeded: 60/78 cases passed (N/A)
         * 
         * Solution2: Sum all of them, then split.
         * Time Complexity: O(n)
         * Accepted: 139ms(84.00%), 78.3MB(71.05%)
         */
#ifdef SOLUTION_2
        // init
        long long int sum = 0;
        int count = 0;

        // Cal the Sum first.
        for(int i = 0; i < nums.size(); i++) sum += nums[i];
        
        // init min_avg and ans
        int min_avg = sum/nums.size();
        int ans = nums.size()-1;

        // The other sum, which is used to split the vector
        long long int sum2 = 0;

        // From the end of the vector (can start from the begin as well)
        for(int i = nums.size()-1; i > 0; i--){

            // Split the vector
            sum -= nums[i];
            sum2 += nums[i];

            // Count the times of the for loop
            count++;

            // tmp = |sum/i - sum2/count|
            int tmp = (sum/i > sum2/count)?(sum/i-sum2/count):(sum2/count-sum/i);

            // if tmp is smaller than min_avg, record it.
            if(min_avg >= tmp){
                min_avg = tmp;
                ans = i-1;
            }

            //cout << tmp << "," << i << "\n";
        }
        return ans;
#endif
#ifdef SOLUTION_1
        if(nums.size() == 1) return 0;
        int min = MAX_INT;
        int ans = nums.size();
        for(int i = 1; i <= nums.size(); i++){
            int tmp = solution1(nums, i);
            if(tmp < min) {
                min = tmp;
                ans = i-1;
            }
            //cout << tmp << "," << i << "\n";
        }
        return ans;
#endif   
    }
#ifdef SOLUTION_1
    int solution1(vector<int>& nums, int index) {
        long long int n1 = 0, n2 = 0;
        int c1 = 0, c2 = 0;
        for(int i = 0; i < index; i++){
            n1 += nums[i];
            c1++;
        }
        if(c1 > 0) n1 /= c1;
        for(int i = index; i < nums.size(); i++){
            n2 += nums[i];
            c2++;
        }
        if(c2 > 0) n2 /= c2;
        return (n1>n2)?n1-n2:n2-n1;
    }
#endif
};
// @lc code=end

