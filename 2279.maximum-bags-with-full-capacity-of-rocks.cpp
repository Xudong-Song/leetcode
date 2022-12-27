/*
 * @lc app=leetcode id=2279 lang=cpp
 *
 * [2279] Maximum Bags With Full Capacity of Rocks
 */

// @lc code=start
class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int add) {
        /**
         * @brief 
         * Solution: Greedy, just fill the smallest c[i]-r[i]
         * Accepted: 192ms(94.29%), 86.8MB(67.47%)
         * 1. count the different of c and r.
         * 2. sort it as ascending.
         * 3. check the diff list from the beginning.
         * 
         * NOTE: think about, if r[i] > c[i], we can get more additional rock.
         */
        int ans = 0;
        vector<int> v(c.size(), 0);
        for(int i = 0; i < c.size(); i++) 
            v[i] = c[i]-r[i];

        sort(v.begin(), v.end());

        for(auto a:v){
            if(a != 0) add -= a;
            if(add < 0) return ans;
            ans++;
        }

        return ans;
    }
};
// @lc code=end

