/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /**
         * @brief 
         * Solution: It works! but the idea is from internet.
         * Example: [1,2,4,2,5,2,7,2,4,9]
         *  1. [1]:
         *     sell2 = max(0, MIN_INT + 1)      =  0
         *     buy2  = max(MIN_INT, sell1 - 1)  = -1
         *     sell1 = max(0, MIN_INT + 1)      =  0
         *     buy1  = max(MIN_INT, 0 - 1)      = -1
         *     
         *  2. [2]:
         *     sell2 = max(0, -1 + 2) =  1
         *     buy2  = max(-1, 0 - 2) = -1
         *     sell1 = max(0, -1 + 2) =  1
         *     buy1  = max(-1, 0 - 2) = -1
         * 
         *  3. [4]:
         *     sell2 = max(1, -1 + 4) =  3
         *     buy2  = max(-1, 1 - 4) = -1
         *     sell1 = max(1, -1 + 4) =  3
         *     buy1  = max(-1, 0 - 4) = -1
         * 
         *  4. [2]:
         *     sell2 = max(3, -1 + 2) =  3
         *     buy2  = max(-1, 3 - 2) =  1
         *     sell1 = max(3, -1 + 2) =  3
         *     buy1  = max(-1, 0 - 2) = -1
         * 
         *  5. [5]:
         *     sell2 = max(3, 1 + 5)  =  6
         *     buy2  = max(1, 3 - 5)  =  1
         *     sell1 = max(3, -1 + 5) =  4
         *     buy1  = max(-1, 0 - 5) = -1
         * 
         *  6. [2]:
         *     sell2 = max(6, 1 + 2)  =  6
         *     buy2  = max(1, 4 - 2)  =  2
         *     sell1 = max(4, -1 + 2) =  4
         *     buy1  = max(-1, 0 - 2) = -1
         * 
         *  7. [7]:
         *     sell2 = max(6, 2 + 7)  =  9
         *     buy2  = max(2, 4 - 7)  =  2
         *     sell1 = max(4, -1 + 7) =  6
         *     buy1  = max(-1, 0 - 7) = -1
         * 
         *  8. [2]:
         *     sell2 = max(9, 2 + 2)  =  9
         *     buy2  = max(2, 6 - 2)  =  4
         *     sell1 = max(6, -1 + 2) =  6
         *     buy1  = max(-1, 0 - 2) = -1
         * 
         *  9. [4]:
         *     sell2 = max(9, 4 + 4)  =  9
         *     buy2  = max(4, 6 - 4)  =  4
         *     sell1 = max(6, -1 + 4) =  6
         *     buy1  = max(-1, 0 - 4) = -1
         * 
         * 10. [9]:
         *     sell2 = max(9, 4 + 9)  = 13
         *     buy2  = max(4, 6 - 9)  =  4
         *     sell1 = max(6, -1 + 9) =  8
         *     buy1  = max(-1, 0 - 9) = -1
         * 
         */

        int sell1 = 0;
        int buy1 = -2147483647;
        int sell2 = 0;
        int buy2 = -2147483647;
        
        for(auto p : prices)
        {
            // Both buy1 and buy2 are trying to save smallest as negative.
            // But buy2 was the biggest different between sell1 and the smallest value after sell1.

            // sell2 is the (biggest different between p and the smallest value) + sell1.
            sell2 = max(sell2, buy2 + p);
            // buy1 will keep the (smallest value as negative) + sell1.
            buy2 = max(buy2, sell1 - p);
            // sell1 will keep the biggest different between p and the smallest value.
            sell1 = max(sell1, buy1 + p);
            // buy1 will keep the smallest value as negative.
            buy1 = max(buy1, 0 - p);

            //cout << "\n" << sell2 << "," << buy2 << "," << sell1 << "," << buy1;
        }

        return sell2;
    }
};
// @lc code=end

