/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution {
public:

    /**
     * @brief Use two point to get the slope of formula y=ax+b
     * 
     * @param point1 point1 (x1, y1)
     * @param point2 point2 (x2, y2)
     * @return pair<double, double> return (a, b)
     */
    pair<double, double> formula(vector<int>& point1, vector<int>& point2){
        double a = 0;
        double b = 0;

        // should declare the variable is double, otherwise, it will become int.
        double dif_x = point1[0]-point2[0];
        double dif_y = point1[1]-point2[1];

        // if the slope isn't infinite.
        if(dif_x != 0) 
        {
            a = dif_y/dif_x;
            b = point1[1]-a*point1[0];
        }

        // if the slope is infinite, return b = x.
        else 
        {
            b = point1[0];
            a = 2147483647;
        }
        
        pair<double, double> f(a,b);
        return f;
    }

    int maxPoints(vector<vector<int>>& points) {
        /**
         * @brief 
         * Solution: Check the slope of two point, Time Complexity: O(n^2)
         *           Accepted, 397ms(12.54%), 33.4MB(6.15%)
         * 
         * 1. Use the formula: y=ax+b to find the max point line.
         * 2. To find the function y=ax+b, we need two point to get the a and b.
         * 3. Use map to build a hash table to store all point at one line.
         */

        // if there is only 1 point, it should has no line,
        // but the question say it should return 1, whatever.
        if(points.size() == 1) return 1;
        int ans = 0;

        // map to store all slope and its point.
        map<pair<double,double>, vector<vector<int>>> slope_map;
        
        // check all combine of each two point.
        for(int i = 0; i < points.size(); i++) 
        {
            for(int j = 0; j < points.size(); j++) 
            {
                if(j == i) continue;

                // get the slope of these two point.
                pair<double,double> p = formula(points[i], points[j]);
                
                // it these two point isn't in the map, store it.
                vector<vector<int>>::iterator it;

                // avoid to store the point[i] more than one time.
                it = find(slope_map[p].begin(), slope_map[p].end(), points[i]);
                if(j == i+1 && it == slope_map[p].end()) slope_map[p].push_back(points[i]);
                
                // because we will tour the whole funciton, we must meet a point twice or more.
                it = find(slope_map[p].begin(), slope_map[p].end(), points[j]);
                if(it == slope_map[p].end()) slope_map[p].push_back(points[j]);
            }
        }
        // check all key in the map, and find the max size of them.
        for(auto const&m : slope_map) 
        {
            int size = m.second.size();
            ans = max(size, ans);
            /*
            cout << "(" << m.first.first << "," << m.first.second << "):\n";
            for(auto v:m.second){
                cout << "(" << v[0] << "," << v[1] << "),";
            }
            cout << endl << endl;
            */
        }
        return ans;
    }
};
// @lc code=end

