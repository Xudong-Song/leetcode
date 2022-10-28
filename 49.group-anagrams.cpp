/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start

//#define SOLUTION_1
#define SOLUTION_2
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /**
         * @brief 
         * Solution1: TLE, 111/117 test case passed.
         *            1. calculate the number of each characters and store it. O(nm)
         *            2. Use the first word to compare other words, if they are "Anagram", 
         *               store it into ans. O(n)
         *            3. When the word is stored, erase it.
         *            4. Total Time complexity O(nm) + O(n) = O(n(m+1)) = O(nm)
         * 
         * Solution2: The same method, but use map. Accepted, 112ms(16.1%), 30.8MB(6.69%)
         *            1. map can classify(分類) the data by the specific(特定) key.
         *               Therfore, when we get a "Anagram" word, we can store it under the same key.
         *            2. because of the feature above, we doesn't need to compare them, we can get the
         *               data from the map directly. 
         * 
         */
        vector<vector<string>> ans;

#ifdef SOLUTION_1
        vector<pair<string, vector<int>>> tmp;

        for(string s:strs){
            pair<string, vector<int>> p;
            vector<int> ch(26,0);
            for(char c:s) ch[c-'a']++;
            
            p.first = s;
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
                    i--;
                }
            }
            ans.push_back(ans_t);
        }
#endif

#ifdef SOLUTION_2
        map<vector<int>, vector<string>> m;
        for(string s:strs){
            vector<int> ch(26,0);
            for(char c:s) ch[c-'a']++;
            m[ch].push_back(s);
        }
        for(auto[hash, v] : m) ans.push_back(v);
#endif

        return ans;
    }
};
// @lc code=end

