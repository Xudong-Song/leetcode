/*
 * @lc app=leetcode id=2446 lang=cpp
 *
 * [2446] Determine if Two Events Have Conflict
 */

// @lc code=start

/*
["06:35","07:15"]\n["16:41","19:36"]
["10:00","11:00"]\n["14:00","15:00"]
["14:13","22:08"]\n["02:40","08:08"]
*/

class Solution {
public:
    int set_time(string& e){
        int m;
        m = (e[3]-'0')*10 + (e[4]-'0') + ((e[0]-'0')*10 + (e[1]-'0'))*60;
        return m;
    }
    bool haveConflict(vector<string>& e1, vector<string>& e2) {
        /**
         * @brief 
         * Solution: 
         * Accetped: 0ms(100%), 11.6MB(45.21%)
         * 1. Get the total m of day for each time.
         * 2. because the event will start and end at the same day.
         *    doesn't need to consider start < end.
         * 3. Return false when times doesn't conflict
         * 
         */
        int m0, m1, m2, m3;
        m0 = set_time(e1[0]);
        m1 = set_time(e1[1]);
        m2 = set_time(e2[0]);
        m3 = set_time(e2[1]);

        if(m0 > m3 || m2 > m1) return false;
        return true;
    }
};
// @lc code=end

