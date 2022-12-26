/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:

    int maxProfit(vector<int>& p) {//[1,2,3,0,2,4]
        if(p.size() <= 1) return 0;

        vector<int> b(p.size()+1, 0);
        vector<int> s(p.size()+1, 0);

        b[1] = -p[0];

        for(int i = 2; i < p.size()+1; i++){
            b[i] = max(b[i-1], s[i-2]-p[i-1]);
            s[i] = max(s[i-1], b[i-1]+p[i-1]);

            cout << p[i-1] << ":" << b[i] << ":" << s[i] << endl;
        }

        return s[p.size()];
    }
};
// @lc code=end

