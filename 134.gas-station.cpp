/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Solution: Just...check if the sum of the path is positive.
        //           But if the sum is always nagetive, I don't know how to exit the loop.

        int ans = -1;
        int gas_remain = 0, i = 0, count = 0;

        while(i < gas.size()){
            // if there is a way to complete the cycle, return the beginning.
            if(ans == i) return ans;

            gas_remain += gas[i] - cost[i];

            if(gas_remain >= 0) {
                if(ans == -1) ans = i;
                //cout << gas[i] << "," << cost[i] << ": " << gas_remain << "," << ans << endl;
            }else {
                count++;
                ans = -1;
                gas_remain = 0;
            }

            // Cycle
            if(ans >= 0 && i == gas.size()-1) i = 0;
            else i++;

            // Don't know how to jump out of the loop, 
            // so I set a counter to check if I just running too many times.
            if(count == gas.size()) return -1;
        }

        return ans;
    }
};
// @lc code=end

