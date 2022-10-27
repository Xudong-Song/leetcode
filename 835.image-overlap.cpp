/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// @lc code=start
class Solution {
public:
    void up(vector<vector<int>>& img1){

    }
    void down(vector<vector<int>>& img1){

    }
    void right(vector<vector<int>>& img1){

    }
    void left(vector<vector<int>>& img1){

    }

    void moving(vector<vector<int>>& img1, vector<vector<int>>& img2, int& ans){
        int ans_tmp = 0;
        for(int i = 0; i < img1.size(); i++){
            for(int j = 0; j < img1[0].size(); i++){
                if(img1[i][j] == 1 && img2[i][j] == 1)
                    ans_tmp++;
            }
        }

        if(ans < ans_tmp){
            ans = ans_tmp;
        }
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans;
        moving(img1, img2, ans);

        return ans;
    }
};
// @lc code=end

