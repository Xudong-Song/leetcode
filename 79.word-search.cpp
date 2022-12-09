/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start

class Solution {
public:
    void find_first(int i, int j, vector<vector<char>>& board, string& word, int count, bool& ans){
        if (word[count] == board[i][j]){
            //cout << word[count] << ":" << count << endl;
            if (count == word.size()-1) {
                ans = true;
                return ;
            }
            char tmp = board[i][j];
            board[i][j] = '0'; //mark the path
            if (i+1 < board.size())     find_first(i+1, j, board, word, count+1, ans);
            if (j+1 < board[0].size())  find_first(i, j+1, board, word, count+1, ans);
            if (i-1 >= 0)               find_first(i-1, j, board, word, count+1, ans);
            if (j-1 >= 0)               find_first(i, j-1, board, word, count+1, ans);
            board[i][j] = tmp; // if the path isn't the anwser, dismark the path.
        }
        return ;
    }

    bool exist(vector<vector<char>>& board, string word) {
        /**
         * @brief 
         * Solution: Use Backtracking to solve this problem.
         * Accepted, 337ms(80.25%), 7.9MB(94.68%)
         * 1. Pass board by value, mark the paths of their own. (Time Limit Exceed)
         * 2. Pass board by reference, mark the path too, but remember to dismark them when the path 
         *    isn't the answer. (Accepted)
         * 
         */

        int n = board.size();
        int m = board[0].size();
        bool ans = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    find_first(i, j, board, word, 0, ans);
                    //cout << "\n";
                    if (ans) return ans;
                }
            }
        }
        return ans;
    }
};


// @lc code=end

