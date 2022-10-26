/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start

//#define SOLUTION_1
#define SOLUTION_3

class Solution {
public:

#ifdef SOLUTION_1
    /**
     * @brief flip all un-mark islands.
     * 
     * @param board the given map
     * @param archipelago the saving islands coordinates.
     * @param n the horizontal limit of the map.
     * @param m the vertical limit of the map.
     */
    void flip(vector<vector<char>>& board, vector<vector<pair<int,int>>>& archipelago, int& n, int& m){
        // number of island
        for(int i = 0; i < archipelago.size(); i++){
            
            bool flag = false;
            // if the island is marked, flip it into 'O', otherwise, flip it into 'X'.
            if(archipelago[i][archipelago[i].size()-1].first  == n && 
                archipelago[i][archipelago[i].size()-1].second == m) flag = true;

            // size of island
            for(int j = 0; j < archipelago[i].size(); j++){
                // coordinate (x,y)
                int x = archipelago[i][j].first;
                int y = archipelago[i][j].second;
                // if the flag is true, it means the islands doesn't need to flip.
                if(flag) {
                    if(x != n && y != m) board[y][x] = 'O';
                }else { 
                    board[y][x] = 'X';
                }
            }
        }
    }

    /**
     * @brief If there is any island touches the border of the map, mark it.
     * 
     * @param archipelago the saving islands coordinates.
     * @param n the horizontal limit of the map.
     * @param m the vertical limit of the map.
     */
    void check_border(vector<vector<pair<int,int>>>& archipelago, int& n, int& m){
        // numbers of island.
        for(int i = 0; i < archipelago.size(); i++){

            // size of island.
            for(int j = 0; j < archipelago[i].size(); j++){

                // if there any pointer touch the border, mark it.
                if(archipelago[i][j].first == 0   || archipelago[i][j].second == 0 || 
                   archipelago[i][j].first == n-1 || archipelago[i][j].second == m-1) 
                {
                    // mark it with the size of the map. (can use other number, e.g., <-1, -1>)
                    pair<int,int> point(n,m);
                    archipelago[i].push_back(point);
                }
            }
        }
    }
#endif

    /**
     * @brief Give a coordinate, search other 'O' by checking its 4 directionally neighbors.
     * 
     * @param board  The given map.
     * @param island if there is 'O', save the coordinates in it.
     * @param x x in coordinates 
     * @param y y in coordinates
     */
    void find_island(vector<vector<char>>& board, 

                    #ifdef SOLUTION_1 
                        vector<pair<int,int>>& island, 
                    #endif

                    int x, int y)
    {
        // if the point is out of range.
        if(x < 0 || y < 0 || x >= board[0].size() || y >= board.size()) return ;

        if(board[y][x] == 'O'){
            // mark the checked coordinates.
            board[y][x] = '#';

#ifdef SOLUTION_1
            // save the point into island.
            pair<int,int> point(x,y);
            island.push_back(point);
            find_island(board, island, x-1, y);
            find_island(board, island, x+1, y);
            find_island(board, island, x, y-1);
            find_island(board, island, x, y+1);
#endif

#ifdef SOLUTION_3
            find_island(board, x-1, y);
            find_island(board, x+1, y);
            find_island(board, x, y-1);
            find_island(board, x, y+1);
#endif
        }
    }

    void solve(vector<vector<char>>& board) {
        /**
         * @brief 
         * Solution1: Accepted, 26ms(49.63%), 22.3MB(5.03%) (Origin)
         * 1. find all island
         * 2. check if islands touch the border of the map.
         * 3. if not, flip the O to X.
         * 
         * Solution2: Doesn't implement (Might be the Fastest Solution)
         * 1. mark all 'O' which is at the border of the board by '#'.
         * 2. check if there is any 'O' near by '#', if true, mark it too.
         * 3. flip all island, if the island is '#', flip it into 'O', otherwise, flip it into 'X'.
         * 
         * Solution3: Accepted, 7ms(99.57%), 10MB(79.74%) (Might be the Spaceless Solution)
         * 1. Use the find_island function, but only check the border island.
         * 2. mark the border island as '#'.
         * 3. flip all island, if the island is '#', flip it into 'O', otherwise, flip it into 'X'.
         */

        // limit of the map.
        int n = board[0].size();
        int m = board.size();

#ifdef SOLUTION_1
        vector<vector<pair<int,int>>> archipelago; // 群島
        // find the first 'O' and get into the find_island function.
        for(int y = 0; y < m; y++) {
            for(int x = 0; x < n; x++) {
                if(board[y][x] == 'O') {
                    // save the coordinates.
                    vector<pair<int,int>> island;
                    // find the coordinates of the island.
                    find_island(board, island, x, y);
                    // after complete the find_island function, save the island into archipelago.
                    archipelago.push_back(island);
                }
            }
        }
        // Check if there is any coordinate touch the border.
        check_border(archipelago, n, m);
        // flip the island according the mark.
        flip(board, archipelago, n, m);
#endif

#ifdef SOLUTION_3

        // find the 'O' and get into the find_island function.
        for(int y = 0; y < m; y++) {
            for(int x = 0; x < n; x++) {
                // only find the border point.
                if(board[y][x] == 'O' && (x == 0 || y == 0 || x == board[0].size()-1 || y == board.size()-1)) 
                    // find the coordinates of the island.
                    find_island(board, x, y);
            }
        }

        // flip the map according the island structure.
        for(int y = 0; y < m; y++) {
            for(int x = 0; x < n; x++) {
                if(board[y][x] == 'O') board[y][x] = 'X';
                else if(board[y][x] == '#') board[y][x] = 'O';
            }
        }
#endif

    }


};
// @lc code=end

