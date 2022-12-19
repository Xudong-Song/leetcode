/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start

// #define SOLUTION1 // TLE
#define SOLUTION2
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
#ifdef SOLUTION2
        /**
         * @brief 
         * Solution2: Really easy to understand solution, DFS.
         * Time Complexity: O(n^2)
         * Accepted: 13ms(48.94%), 7MB(99.45%)
         * 1. Check if there is valid point, if yes, put your Queen here.
         * 2. When ever we put a Queen, we should move to next row/col avoid 
         *    double execute.
         * 3. Because of 2., we should just look up col/row of the vector.
         * 4. Before we move to next col/row, we should restore default.
         * 
         */
        vector<vector<string>> ans;
        // Use vector string instead of map, and full-up them as '.'
        vector<string> v(n,string(n,'.'));
        DFS(n, v, 0, ans);
        return ans;
#endif


#ifdef SOLUTION1
        /**
         * @brief 
         * Solution: Backtracking
         * Time Limit Exceeded: 7/9 cases passed (N/A)
         * Time Complexity: O(m^n), which m is the number of the numark 
         *                  points.
         * 1. Move one Queen on the board, and mark the attack range.
         * 2. Trail to move another Queen to all unmark points, and mark
         *    the attack range as well.
         * 3. When there is no unmark point, check the depth, if the
         *    depth is same as n, record it as answer.
         * 
         * Before Optimized (n=6, 2600ms)
         * Optimized:
         * 1. If the blank point at the same level has been trail, mark
         *    it. (n=6, 1000ms)
         *    1.1 Add Marking the node that just passed.
         * 2. Doesn't need to execute the middle of the map, just trail
         *    the edge of it. (n=7, 1000ms)
         * 3. Doesn't need to execute all edge, one of them is enough.
         *    (n=7, 600ms)
         * 4. If only execute one edge, there is no need to check the
         *    iterator. (n=7, 600ms)
         * 
         * 5. Might rotate the map instead of compute it directly. (Plan)
         *    -> Problem: How to avoid the rotated solution?
         * 
         */
        vector<vector<string>> ans;
        // 1.point(x,y)  2.status
        map<pair<int, int>, int> m;

        // init
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                pair<int, int> p = {i, j};
                m[p] = 0;
            }
        }

        // map<pair<int, int>, int> tmp_map = m;
        for(int i = 0; i < n; i++){
            pair<int, int> p = {i, 0};
            Backtracking_(n, m, 2, ans, p);
            // cout << "-----------------------------\n";
            // m = tmp_map;
        }
        
        return ans;
#endif
    }

private:
#ifdef SOLUTION2
    void DFS(int& n, vector<string>& v, int row, 
                            vector<vector<string>>& ans)
    {
        // Record the answer.
        if(row == n) ans.push_back(v);

        for(int i = 0; i < n; i++){
            // Check if the point is valid
            if(is_valid(n, v, {i, row})){
                // If yes, put a Queen here.
                v[i][row] = 'Q';
                // if there is a valid Q, we should start from the next row.
                DFS(n, v, row+1, ans);
                // Before we get into next col, restore default.
                v[i][row] = '.';
            }
        }
    }

    // Check if the point is valid.
    bool is_valid(int& n, vector<string>& v, pair<int, int> p) {
        int x = p.first, y = p.second;
        for(int i = 0; i < n; i++){
            if(v[x][i] == 'Q') return false; // row
            if(v[i][y] == 'Q') return false; // col
            if(x-i >= 0){
                if(y-i >= 0) if(v[x-i][y-i] == 'Q') return false;
                if(y+i < n)  if(v[x-i][y+i] == 'Q') return false;
            }
            if(x+i < n){
                if(y-i >= 0) if(v[x+i][y-i] == 'Q') return false; 
                if(y+i < n)  if(v[x+i][y+i] == 'Q') return false;
            }
        }
        return true;
    }
#endif

#ifdef SOLUTION1
    /**
     * @brief Record the answer
     * 
     * @param n 
     * @param m 
     * @param ans 
     */
    void print(int& n, map<pair<int, int>, int> m, vector<vector<string>>& ans)
    {
        vector<string> tmp;
        for(int i = 0; i < n; i++){
            string s;
            for(int j = 0; j < n; j++){
                if(m[{i,j}] == 1) s+=".";
                else s+="Q";
            }
            tmp.push_back(s);
        }
        /*vector<vector<string>>::iterator it = find(ans.begin(), ans.end(), tmp);
        if(it == ans.end())*/ 
            ans.push_back(tmp);
    }

    /**
     * @brief Find all blank point.
     * 
     * @param m 
     * @return vector<pair<int, int>> 
     */
    vector<pair<int, int>> find_blank(map<pair<int, int>, int> m)
    {
        vector<pair<int, int>> v;
        for(auto a:m)
            if(a.second == 0)
                v.push_back(a.first);
        return v;
    }    
    
    /**
     * @brief Record the Attack range, and Return the blank point list.
     * 
     * @param n 
     * @param p 
     * @param count 
     * @param m 
     * @return vector<pair<int,int>> 
     */
    vector<pair<int,int>> Attack(int& n, pair<int, int>& p, int count,
                                            map<pair<int, int>, int>& m)
    {
        int x = p.first, y = p.second;
        for(int i = 0; i < n; i++) {
            if(x-i >= 0) m[{x-i, y}] = 1; //left
            if(x+i < n)  m[{x+i, y}] = 1; //right
            if(y-i >= 0) m[{x, y-i}] = 1; //up
            if(y+i < n)  m[{x, y+i}] = 1; //down
            if(x-i >= 0 && y-i >= 0) m[{x-i, y-i}] = 1; // left-up
            if(x-i >= 0 && y+i < n ) m[{x-i, y+i}] = 1; // left-down
            if(x+i < n  && y-i >= 0) m[{x+i, y-i}] = 1; // right-up
            if(x+i < n  && y+i < n ) m[{x+i, y+i}] = 1; // right-down
        }
        m[p] = count;

        // Get the blank point list.
        vector<pair<int,int>> v = find_blank(m);
        return v;
    }

    /**
     * @brief Backtracking, use the blank point list for the next level.
     * 
     * @param n 
     * @param m 
     * @param count depth of the level
     * @param ans 
     * @param p 
     */
    void Backtracking_(int& n, map<pair<int, int>, int>& m, int count,
                        vector<vector<string>>& ans, pair<int, int>& p)
    {
        // record the map, avoid to miss the data.
        map<pair<int, int>, int> tmp_map = m;

        // Get the blank point list from the Attack function.
        vector<pair<int,int>> v = Attack(n, p, count, m);

        // cout << "(" << p.first << "," << p.second << "):" << m[p] << endl;

        // If there is no blank point, record it as the answer.
        if(v.size() == 0)
            if(count == n+1)
                print(n, m, ans);

        m[p] = -1;
        for(auto a:v){
            if(m[a] != -1){
                m[a] = -1; // mark the point which is at the same level.
                Backtracking_(n, m, count+1, ans, a);// Backtracking
            }
        }

        // Replace the map.
        m = tmp_map;
    }
#endif
};
// @lc code=end

