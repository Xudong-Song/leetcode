/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Solution: buy at the feet, sell at the top. (Greedy & Two Pointer)

        // if there is only one, return 0.
        if(prices.size() <= 1)
        {
            return 0;
        }

        int feet = prices[0];
        int top = 0;
        int ans = 0;
        int i = 1;
        
        for(; i < prices.size() - 1; i++)
        {
            // If there is a smaller one, update the feet value
            if(prices[i] < prices[i-1])
            {
                feet = prices[i];
            }
            
            // If there is a bigger one, update the top value
            if(prices[i] > prices[i-1])
            {
                top = prices[i];
            }

            // If it is going to be fall, sell it.
            if(prices[i] > prices[i+1] && top > feet)
            {
                ans += top-feet;
                top = 0;
                feet = 0;
            }
            //cout << ans << "," << feet << "," << top << endl;
        }

        // if the last one is bigger than its previous one.
        if(prices[i] >= prices[i-1] && prices[i] > feet)
        {
            ans += prices[i] - feet;
            //cout << ans << "," << feet << "," << prices[i] << endl;
        }

        return ans;
    }
};
// @lc code=end

