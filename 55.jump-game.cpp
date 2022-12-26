/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        // Solution1: Greedy 檢查每格能reach到的最遠範圍，如果最遠能碰到last則回傳true
        // 時間複雜度: O(n), Status: Accepted, 64ms(94.61%), 48.3MB(94.13%)
        
        if (nums.size() == 1) return true;
        
        int max = nums[0];
        for(int i = 0; i <= max; i++){//反正每一格都走，走到當前能走到的最遠處(max)->以此方法規避Dynamic Programming重複計算的問題
            if(max < i + nums[i]) // 檢查max是否需要更新
                max = i + nums[i];
            if(max >= nums.size()-1) // 檢查max是否達到nums的長度
                return true;
        }
        
        return false;
    }
};
// @lc code=end

