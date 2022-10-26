/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 */

// @lc code=start
class Solution {
public:
    bool checkIfPangram(string s) {
        set<char> myset;
        for(int i = 0; i < s.size(); i++){
            myset.insert(s[i]);
            if(myset.size() == 26){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

