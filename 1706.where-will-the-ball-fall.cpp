/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 */

// @lc code=start
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        int m = grid.size();
        int n = grid[0].size();
        for(int x = 0; x < n; x++){
            int ball = x;
            for(int y = 0; y < m; y++){
                int tunnel = grid[y][ball];
                ball+=tunnel;
                // 1. ball is hitting to the matrix's wall.
                if((ball >= n || ball < 0)
                // 2. ball is stucked at the tunnel.
                ||(tunnel == 1 && grid[y][ball] == -1)
                ||(tunnel == -1 && grid[y][ball] == 1)){
                    ball = -1;
                    cout << ball << ",";
                    break;
                }
                cout << ball << ",";
                
            }
            cout << endl;
            ans.push_back(ball);
        }
        return ans;
    }
};
// @lc code=end

