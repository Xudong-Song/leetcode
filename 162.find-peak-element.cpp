/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /**
         * @brief 
         * Solution1: Try binary-search
         * Accepted, 6ms(74.05%), 8.8MB(51.87%)
         * 1. Just... binary search, don't know why this is medium.
         * 
         */
        if(nums.size() <= 1) return 0;
        if(nums.size() == 2) {
            if(nums[0] > nums[1]) return 0;
            else return 1;
        }
        
        int min = 0;
        int max = nums.size()-1;
        int mid = (min+max)/2;
        while(mid != min && mid != max){
            //cout << nums[mid-1] << "\n" << nums[mid+1] << "\n";
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

            if(nums[mid-1] > nums[mid+1]) max = mid;
            else min = mid;

            mid = (min+max)/2;
        }

        if(nums[max] > nums[min]){
            if(nums[mid] > nums[max]) return mid;
            else return max;
        }else{
            if(nums[mid] > nums[min]) return mid;
            else return min;
        }
        
    }
};
// @lc code=end

