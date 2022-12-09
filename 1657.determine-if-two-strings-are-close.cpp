/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        /**
         * @brief 
         * Solution: 
         * 1. Chars in word1 should consist with chars word2
         * 2. The freq of chars in word1 should consist with The freq of chars in 
         *    word2
         * Time Complexity: O(n + m + 2logn + 2logm + 2) = O(n + m)
         * Accepted: 138ms(79.85%), 21MB(10.04%)
         * 
         */
        map<char, int> m1;
        map<char, int> m2;
        for(auto w: word1) m1[w]++; // O(n)
        for(auto w: word2) m2[w]++; // O(m)
        vector<char> v1_c;
        vector<int> v1_i;
        for(auto m: m1){ // O(1)
            v1_c.push_back(m.first);
            v1_i.push_back(m.second);
        }
        vector<char> v2_c;
        vector<int> v2_i;
        for(auto m: m2){ // O(1)
            v2_c.push_back(m.first);
            v2_i.push_back(m.second);
        }
        sort(v1_c.begin(), v1_c.end()); // O(logn)
        sort(v1_i.begin(), v1_i.end()); // O(logn)
        sort(v2_c.begin(), v2_c.end()); // O(logm)
        sort(v2_i.begin(), v2_i.end()); // O(logm)

        if(v1_c == v2_c && v1_i == v2_i) return true;
        else return false;
    }
};
// @lc code=end

