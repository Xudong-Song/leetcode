/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {

private:
    void solution1(vector<int>& nums, int& k){ 
        /**
         * @brief 
         * Solution1: Insert and Erase
         * Status: TLE, 37/38 cases passed (N/A)
         * Time Complexity: O(n*k) -> Both insert() & erase are O(n) in C++.
         * Space Complexity: O(1)
         * 
         */
        k %= nums.size();
        for(int i = 0; i < k; i++){
            nums.insert(nums.begin(), nums[nums.size()-1]);
            nums.erase(nums.end()-1);
        }
    }
    void solution2(vector<int>& nums, int& k){
        /**
         * @brief 
         * Solution2: Store the data directly.
         * Accepted, 30ms(91.19%), 26.4MB(5.13%)
         * Time Complexity: O(n)
         * Space Complexity: O(n)
         * 
         */
        
        int n = nums.size();
        vector<int> v;
        k %= n;

        for(int i = k; i > 0; i--) v.push_back(nums[n-i]);
        for(int i = 0; i < n-k; i++) v.push_back(nums[i]);

        nums = v;
    }
    void solution3(vector<int>& nums, int& k){
        /**
         * @brief 
         * Solution2: Swap
         * 
         * Time Complexity: O(n)
         * Space Complexity: O(1)
         * 
         */

        int n = nums.size();
        int index = 0;
        int tmp = 0;
        k %= n;
        for(int i = k; i > 0; i--){
            tmp = nums[index];
            nums[index] = nums[n-i];
            nums[n-i] = tmp;
            index++;
        }

        for(auto v:nums){
            cout << v << ",";
        }cout << endl;


    }
public:
    
    void rotate(vector<int>& nums, int k) {
        
        solution2(nums, k);


    }
};
// @lc code=end

