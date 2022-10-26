/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:

    /**
     * @brief check if tmp is equal the reversed of itself.
     * 
     * @param tmp split from given string.
     * @return true 
     * @return false 
     */
    bool is_palindrome(string tmp) {
        string tmp_re;
        for(int i = tmp.size() - 1; i >= 0; i--) tmp_re.push_back(tmp[i]);
        if(tmp == tmp_re) return true;
        else return false;
    }

    /**
     * @brief backtracking: check all combination to get the answer.
     * 
     * @param ans final answer
     * @param current_list save all palindrome
     * @param tmp split s into tmp, and check if it is palindrome.
     * @param s given string
     * @param index index of the given string
     */
    void backtracking(  vector<vector<string>>& ans, 
                        vector<string> current_list, 
                        string tmp, string& s, int index  ) 
    {
        for(int i = index; i < s.size(); i++){
            tmp.push_back(s[i]);
            // check if tmp is palindrome.
            if(is_palindrome(tmp)){
                // move to next char
                backtracking(ans, current_list, tmp, s, i+1);
                // save it.
                current_list.push_back(tmp);
                // when find a palindrome, find next one.
                tmp = {};
            }

        }

        int length = 0;
        // if the size of current_list is as long as s, save it.
        for(int j = 0; j < current_list.size(); j++) length += current_list[j].size();
        if(length == s.size()) ans.push_back(current_list);
    }

    vector<vector<string>> partition(string s) {
        /* Solution: Backtracking, Accepted, 195ms(72.24%), 128MB(24.36%)
         * 1. Find the palindrome.
         * 2. If find a palindrome, split it.
         * 3. Save all palindrome in the same string into current_list.
         * 4. if the current_list is as long as the given string, save it.
         * 
         * e.g.: "aab"
         * 
         * 1. tmp = "a" (is palindrome)
         *    current_list (1) = ["a"]
         * 
         * 2. tmp = "aa" (is palindrome)
         *    current_list (2) = ["aa"]
         * 
         * 3. tmp = "aab" (not palindrome)
         * 
         * 4. tmp = "b" (is palindrome) -> recursive is working as stack, last in, first out.
         *    current_list (2) = ["aa", "b"]
         *    ans = [["aa", "b"]]
         * 
         * 5. tmp = "a" (is palindrome)
         *    current_list (1) = ["a", "a"]
         * 
         * 6. tmp = "b" (is palindrome)
         *    currnet_list (1) = ["a","a","b"]
         *    ans = [["aa", "b"],["a","a","b"]]
         * 
         */
        vector<vector<string>> ans;
        vector<string> current_list;
        string tmp;

        backtracking(ans, current_list, tmp, s, 0);

        return ans;
    }
};
// @lc code=end

