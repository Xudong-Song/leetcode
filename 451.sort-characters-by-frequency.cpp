/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        /**
         * @brief 
         * Solution: Use map record the freq of char, then use vector to sort by
         *           freq.
         * Time Complexity: O(NlogN)
         * Accepted: 27ms(53.8%), 8.6MB(45.74%)
         * 
         */
        map<char, int> m;
        vector<pair<int, char>> v;
        string ans;

        for(int i = 0; i < s.size(); i++) // O(N)
            m[s[i]]++;

        for(auto a:m){
            pair<int, char> p;
            p = {a.second, a.first};
            v.push_back(p);
            //cout << a.first << ":" << a.second << endl;
        }
        sort(v.rbegin(), v.rend()); // O(logN)

        for(auto a:v)
            for(int i = 0; i < a.first; i++)
                ans += a.second;
            
        return ans;
    }
};
// @lc code=end

