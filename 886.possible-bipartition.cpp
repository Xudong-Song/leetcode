/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start
// 7\n[[1,2],[3,4],[4,5],[3,5],[6,7]]
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        /**
         * @brief 
         * Solution 1: I Don't Know WTF is this. 
         * Time Complexity: O(n * dis.size())
         * Accepted: 315ms(70.25%), 71.7MB(30.39%)
         * 1. Record everyone's hater.
         * 2. Make No.1 be first time, and make sure they are in difference 
         *    teams.
         * 3. If they are in the same team, return false.
         * 4. Because there are same cases need's to check from behind, 
         *    check it from the end of the list.
         * 
         * Note: It's actully not a very good solution. 
         *       If the Question is:
         *       ---------------------------------------------
         *       | n = 7                                     |
         *       | dislike = [[1,2],[3,4],[4,5],[3,5],[6,7]] |
         *       ---------------------------------------------
         *       It will be wrong answer.
         *           
         * 
         */
        vector<vector<int>> h(n+1);
        vector<int> color(n+1, 0);
        
        for(auto d:dis){
            h[d[0]].push_back(d[1]);
            h[d[1]].push_back(d[0]);
        }

        color[1] = 1;
        for(int i = 1; i < h.size(); i++){
            //cout << i << ":";
            if(color[i] == 0) continue;

            bool c1 = false;
            if(color[i] == 1) c1 = true;

            for(auto hh:h[i]){
                //cout<< hh << ",";
                if(c1) {
                    if(color[hh] == 1) return false;
                    else color[hh] = 2;
                }else{
                    if(color[hh] == 2) return false;
                    else color[hh] = 1;
                }
            }
            //cout << endl;
        }

        vector<int> color2(n+1, 0);
        color2[n] = 1;
        for(int i = n; i >= 0; i--){
            //cout << i << ":";
            if(color2[i] == 0) continue;

            bool c1 = false;
            if(color2[i] == 1) c1 = true;

            for(auto hh:h[i]){
                //cout<< hh << ",";
                if(c1) {
                    if(color2[hh] == 1) return false;
                    else color2[hh] = 2;
                }else{
                    if(color2[hh] == 2) return false;
                    else color2[hh] = 1;
                }
            }
            //cout << endl;
        }

        
        return true;
    }
};
// @lc code=end

