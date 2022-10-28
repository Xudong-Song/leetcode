/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /**
         * @brief 
         * Solution1: TLE, 111/117 test case passed.
         *            1. calculate the number of each characters and store it. O(nm)
         *            2. Use the first word to compare other words, if they are Anagram, store it into ans. O(n)
         *            3. When the word is stored, erase it.
         *            4. Total Time complexity O(nm) + O(n) = O(n(m+1)) = O(nm)
         * 
         */

        vector<vector<string>> ans;
        vector<pair<string, vector<int>>> tmp;

        for(int i = 0; i < strs.size(); i++){
            pair<string, vector<int>> p;
            vector<int> ch(26,0);
            for(int j = 0; j < strs[i].size(); j++){
                ch[strs[i][j]-'a']++;
            }
            p.first = strs[i];
            p.second = ch;
            tmp.push_back(p);
        }

        while(!tmp.empty()){
            vector<string> ans_t;
            vector<int> ch_t = tmp[0].second;
            ans_t.push_back(tmp[0].first);
            tmp.erase(tmp.begin());

            for(int i = 0; i < tmp.size(); i++){
                if(ch_t == tmp[i].second){
                    ans_t.push_back(tmp[i].first);
                    tmp.erase(tmp.begin()+i);
                    //i--;
                }
            }
            ans.push_back(ans_t);
        }

        return ans;
    }
};
// @lc code=end

