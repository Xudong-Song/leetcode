/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start

//#define SOLUTION_1
//#define SOLUTION_2
#define SOLUTION_3
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
         * Solution3: The same method, but use unordered_map. Accpted, 77ms(49.65%), 19.7MB(72.23%)
         *            1. Don't know WTF is 0x01e9a5f423bcd687ull, but it works.
         *            2. OK I get it, the 0x01e9a5f423bcd687ull is just a long enough number, 
         *               we can use another number which is also long enough to change it.
         *               And the ending "ull" means unsigned long long, can use "ULL" instead.
         *            3. After change the number 0x01e9a5f423bcd687ull to 0x1234567891011ULL, the 
         *               result status is become 34ms(96.69%), 19.8MB(72.23%), not sure the reason.
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

#ifdef SOLUTION_3
        unordered_map<size_t, vector<string>> m;
        
        for(string s:strs){
            size_t u = 0;
            for(char c:s){
                const auto a = c * 0x1234567891011ULL;
                u += a ^ (a >> 35);
            }
            m[u].push_back(s);
        }

        for(auto[_, v] : m) ans.push_back(v);
#endif

        return ans;
    }
};
// @lc code=end

