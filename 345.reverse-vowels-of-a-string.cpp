/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        /**
         * @brief 
         * Solution: 
         * 1. Record if the c in s is vowels, and reverse it. O(n)
         * 2. Check c in s again, and print the recorded vowel when c is vowel. O(n)
         * Accepted, 32ms(6.81%), 8.5MB(10.55%).
         * 
         */

        string ans;

        vector<char> v;
        for(int i = s.size()-1; i >= 0; i--)
            if(s[i] == 'a' || s[i] == 'e'|| s[i] == 'i'|| s[i] == 'o'|| s[i] == 'u'||
               s[i] == 'A' || s[i] == 'E'|| s[i] == 'I'|| s[i] == 'O'|| s[i] == 'U')
                v.push_back(s[i]);
        
        int index = 0;
        for(char c:s){
            if(c == 'a' || c == 'e'|| c == 'i'|| c == 'o'|| c == 'u'||
               c == 'A' || c == 'E'|| c == 'I'|| c == 'O'|| c == 'U'){
                ans.push_back(v[index]);
                index++;
            }else{
                ans.push_back(c);
            }
        }

        return ans;
    }
};
// @lc code=end

