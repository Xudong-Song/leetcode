/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    void tour_this_island(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return ;

        if(grid[i][j] == '1'){
            grid[i][j] = '2';
            tour_this_island(grid, i+1, j);
            tour_this_island(grid, i-1, j);
            tour_this_island(grid, i, j+1);
            tour_this_island(grid, i, j-1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        /**
         * @brief 
         * Solution: Just...find and record the number of islands.
         *           Accepted, 40ms(90.71%), 12.3MB(60.85%);
         * 1. find a piece of island.
         * 2. tour this island by walking 4 direction, and mark the passing part.
         * 3. record if we find a new island.
         * 
         */

        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    //cout << "get it\n";
                    tour_this_island(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

