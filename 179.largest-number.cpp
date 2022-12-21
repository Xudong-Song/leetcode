/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:

    /**
     * @brief Use for sort() function, if return true, 
     *        s1 will be the first. vice versa
     *          
     * Note: Remeber Use static, or sort function can
     *       not use this compare function.
     * 
     * @param s1 string 1
     * @param s2 string 2
     * @return true
     * @return false
     */
    static bool compare(string& s1, string& s2){
        //cout << s1 << ":" << s2 << endl;
        return s1+s2>s2+s1; 
    }

    string largestNumber(vector<int>& nums) {
        /**
         * 
         * @brief Sort (Not my idea, but I learn how
         *        to use customize sort)
         * Time Complexity: O(nlogn)
         * Accepted: 14ms(68.1%), 11.4MB(41.8%)
         * 1. Turn all number into string.
         * 2. Use sort function with customize sort.
         *    -> Add the string with difference way, 
         *       then compare them directly.
         */
        // [111311, 1113]
        vector<string> vv;
        for(auto n:nums) vv.push_back(to_string(n));

        sort(vv.begin(), vv.end(), compare);

        string ans;
        for(auto s:vv){
            //cout << s << " ";
            ans += s;
        }
        if(ans[0] == '0') return "0";
        return ans;
    }
};
// @lc code=end

