/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution {
public:
    int solution2(int x, int y, int& n, int& m, vector<vector<int>>& dungeon, vector<vector<int>>& map) {
        
        //cout << x << "," << y << endl;
        if(x >= m || y >= n) return 2147483647; //MAX_INT
        if(map[y][x] != 2147483647) return map[y][x];
        if(x == m-1 && y == n-1) {
            dungeon[y][x] = (1-dungeon[y][x] <= 0 )?1:(1-dungeon[y][x]);
            map[y][x] = dungeon[y][x];
            return dungeon[y][x];
        }

        int r = solution2(x+1, y, n, m, dungeon, map);
        int d = solution2(x, y+1, n, m, dungeon, map);
        dungeon[y][x] = ((min(r, d) - dungeon[y][x]) <= 0)?1:(min(r, d) - dungeon[y][x]);
        map[y][x] = dungeon[y][x];

        return dungeon[y][x];
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        /**
         * @brief 
         * --------------------------------------------------------------------------------------------
         * Solution1: Time Complexity: O(2^n) or O(2^m) => too slow.
         * 1. find all path of the dungeon, and record the cost.
         * --------------------------------------------------------------------------------------------
         * Solution2: Time Complexity: O(m*n)
         * Accepted, 15ms(49.28%), 8.9MB(53.29%)
         * 1. The value of the buttom-right node is 1-dungeon(m, n) or 1.
         *    (1) if the value is "lower" than 0, it means the value of the buttom-right is positive, 
         *        we will not lose hp at this node, therefore, we only need 1 HP to service.
         *    (2) if not, is means there is a demon at the node, we should have 1-dungeon(m, n) HP
         *        to service.
         * 2. For other nodes, every node is decided by their right and down node:
         *    The value is: min(dungeon(x+1,y), dungeon(x,y+1)) - dungeon(x,y) or 1
         *    (1) if the value is "bigger" than 0, dungeon(x,y) = value, it means there is a demon at 
         *        the node, and we need at least (min(dungeon(x+1,y), dungeon(x,y+1)) - dungeon(x,y))
         *        to pass this node and next node.
         *    (2) if not, it means the node we stand is a magic orbs, and the next step is also a 
         *        magic orbs. Therefore, we only need 1 HP to pass this node and next node.
         * 3. Build a map to avoid duplicate processing. (Dynamic Programming)
         * 4. The node dungeon(0,0) will be the answer.
         * --------------------------------------------------------------------------------------------
         *    
         */
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> map(n+1, vector<int>(m+1, 2147483647));
        solution2(0, 0, n, m, dungeon, map);
        
        /*for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << dungeon[i][j] << ",";
            }
            cout << endl;
        }*/

        return dungeon[0][0];
    }
};
// @lc code=end

