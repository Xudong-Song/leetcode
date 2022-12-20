/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0);
    }
    
    void solve(vector<vector<char>>& board, int count) {
        // Solution1: 用遞迴的方式找
        // 1. 每次遞迴都找目前每個空格可填入的數字
        // 2. 如果只能填入一個數字則填入，直到每格都填滿
        // Bouns: 若某數字已確定必定出現在某行/列 也要列入考量
        
        // 存入缺少的部分
        vector<vector<string>> cell; // 小格(cell)
        // 1. 先找列 (配合輸入結構 方便判斷)
        for(int i = 0; i < 9; i++){
            vector<string> lack_r;
            string row;
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    size_t found_row = row.find(board[i][j]);
                    if(found_row == string::npos){
                        row.push_back(board[i][j]);
                    }
                }
            }
            for(int j = 0; j < 9; j++){
                string lack;
                for(int k = 1; k <= 9; k++){
                    size_t found_row = row.find(k + '0');
                    if(board[i][j] == '.'){
                        if(found_row == string::npos){
                            lack.push_back(k + '0');
                        }
                    }
                }
                lack_r.push_back(lack);
            }
            cell.push_back(lack_r);
        }
        // 2. 找行
        for(int i = 0; i < 9; i++){// 往右邊
            for(int j = 0; j < 9; j++){// 往下面
                if(board[j][i] != '.'){// 找到數字的話從cell刪掉
                    char num = board[j][i];
                    // cout << "find: " << num << " \n";
                    for(int k = 0; k < 9; k++){
                        if(board[k][i] == '.'){// 針對整行的空格
                            size_t found_col = cell[k][i].find(num);
                            if(found_col != string::npos){
                                cell[k][i].erase( remove(cell[k][i].begin(), cell[k][i].end(), num), cell[k][i].end() );
                            }
                        }
                    }
                }
            }
        }
        // 3. 找九宮格(box)
        int a = 0, b = 0;
        while(b < 9){
            string box;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(board[i+b][j+a] != '.'){// 找到數字的話從cell刪掉
                        char num = board[i+b][j+a];
                        // cout << "find:" << num << endl;
                        for(int k = 0; k < 3; k++){// 針對整個九宮格
                            for(int l = 0; l < 3; l++){
                                if(board[k+b][l+a] == '.'){// 針對整個九宮格的空格
                                    size_t found_box = cell[k+b][l+a].find(num);
                                    // cout << cell[k+b][l+a] << endl;
                                    if(found_box != string::npos){// 有找到的話
                                        cell[k+b][l+a].erase( remove(cell[k+b][l+a].begin(), cell[k+b][l+a].end(), num), cell[k+b][l+a].end() );
                                    }
                                }
                            }
                        }
                    }
                }
            }
            a+=3;
            if(a>=9){ b+=3; a=0; }
        }
        
        // 4. 其他方法
        // (1) 整個九宮格內只有一格可以填入某數則填入，即使此格仍有其他選擇
        // (2) 顯性三鏈數: 如果一個宮(box)或行列內有共軛的數字，則可以將同一個宮(box)或行列的其他格內的此數刪除
        // (3) 強鏈: 如果某數只會出現在當前行列內，則其他行列需考量此選項
        // (4) 窮舉法: 把尚未填入的空格以可能的數值填滿，直到找到解
/*[
["8",".",".",".",".",".",".",".","."],
[".",".","3","6",".",".",".",".","."],
[".","7",".",".","9",".","2",".","."],
[".","5",".",".",".","7",".",".","."],
[".",".",".",".","4","5","7",".","."],
[".",".",".","1",".",".",".","3","."],
[".",".","1",".",".",".",".","6","8"],
[".",".","8","5",".",".",".","1","."],
[".","9",".",".",".",".","4",".","."]
]*/
        
        
        // 找完了 給值
        bool flag = false;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                //if(count == 6){
                     //cout << cell[i][j] << endl;
                //}
                if(cell[i][j].size() == 1){
                    flag = true;
                    board[i][j] = cell[i][j][0];
                }
            }
        }
        count++;
        if(flag)
            solve(board, count);
    }
};
// @lc code=end

