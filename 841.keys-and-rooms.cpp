/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
public:
    void DFS(vector<vector<int>>& r, int index, vector<bool>& mark) 
    {
        mark[index] = true;
        for(auto i:r[index])
            if(mark[i] == false)
                DFS(r, i, mark);
    }
    
    bool canVisitAllRooms(vector<vector<int>>& r) {
        /**
         * @brief 
         * Solution: DFS
         * Time Comlexity: O(n)
         * Accepted: 15ms(70.14%), 10.3MB(80.63%)
         * 1. Start from the room 0, then goto another room
         *    refer to the keys inside the room 0.
         * 2. Mark the room just passed.
         * 3. If there is no enabled room, check the mark.
         *    If any of them is unmarked, return false.
         * 
         */
        bool ans;
        vector<bool> mark(r.size(), false);
        DFS(r, 0, mark);
        for(auto m:mark) 
            if(m == false) 
                return false;

        return true;
    }
};
// @lc code=end

