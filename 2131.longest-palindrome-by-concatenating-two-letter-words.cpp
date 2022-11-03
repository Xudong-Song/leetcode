/*
 * @lc app=leetcode id=2131 lang=cpp
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
 */

// @lc code=start
class Solution {
public:

    bool is_repeat(string w){
        if(w[0] == w[1]) return true;
        return false;
    }

    string reverse_w(string w){
        string rw;
        rw.push_back(w[1]);
        rw.push_back(w[0]);
        return rw;
    }

    int longestPalindrome(vector<string>& words) {
        /**
         * @brief 
         * Solution: Greedy, Find the reverse word instead of actually arrange them.
         * Accepted, 1208ms(17.01%), 167.9MB(60%).
         * 
         * 1. Count the word in vector, and record the number of them with map.
         * 2. If there is a reverse word in the record map, ans+4, map[w]-1, map[m]-1
         * 3. After step 2, if there is a palindrome string in the map, ans+=2, and it is the answer.
         * 
         */

        int ans = 0;
        map<string, int> map_w;
        for(string w:words) map_w[w]++;

        for(auto const& map:map_w){
            string m = map.first;
            if(is_repeat(m)){
                ans += (map_w[m]/2)*4;
                map_w[m] %= 2;
            }else{
                string w = reverse_w(map.first);
                int times = min(map_w[m], map_w[w]);
                map_w[m] -= times;
                map_w[w] -= times;
                ans += times*4;
            }
        }

        for(auto const& map:map_w){
            if(is_repeat(map.first) && map.second > 0){
                ans += 2;
                break;
            }
        }

        return ans;
    }
};
// @lc code=end

