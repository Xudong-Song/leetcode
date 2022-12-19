/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
public:
    bool is_valid(int n, vector<string> v, pair<int, int> p) {
        int x = p.first, y = p.second;
        for(int i = 0; i < n; i++){
            if(v[x][i] == 'Q') return false;
            if(v[i][y] == 'Q') return false; 

            if(x-i >= 0){
                if(y-i >= 0) {
                    if(v[x-i][y-i] == 'Q') 
                        return false;
                }
                if(y+i < n) {
                    if(v[x-i][y+i] == 'Q') 
                        return false;
                }
            }
            if(x+i < n){
                if(y-i >= 0) {
                    if(v[x+i][y-i] == 'Q')
                        return false; 
                }
                if(y+i < n) {
                    if(v[x+i][y+i] == 'Q')
                        return false;
                } 
            }
        }
        return true;
    }

    void backtracking(int n, vector<string>& v, int row, int& ans) {
        if(row == n) ans++;
        for(int i = 0; i < n; i++){
            if(is_valid(n, v, {i, row})){
                v[i][row] = 'Q';
                // if ther is a valid Q, we should start from the next row.
                backtracking(n, v, row+1, ans);
                v[i][row] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        int ans = 0;
        vector<string> v(n,string(n,'.')); // Use string intead of another vector
        backtracking(n, v, 0, ans);
        return ans;
    }
};
// @lc code=end

