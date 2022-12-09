/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
class Solution {
public:
    bool is_vowel(char c){
        char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i = 0; i < 10; i++)
            if(c == vowels[i]) return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int v1 = 0, v2 = 0;
        
        for(int i = 0; i < s.size()/2; i++) 
            if(is_vowel(s[i])) v1++;

        for(int i = s.size()/2; i < s.size(); i++) 
            if(is_vowel(s[i])) v2++;

        if (v1 == v2) return true;
        else return false;
    }
};
// @lc code=end

