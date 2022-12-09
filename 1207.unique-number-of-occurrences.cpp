/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;
        vector<pair<int, int>> v;
        for(auto a:arr) m[a]++;
        for(auto a:m){
            pair<int, int> p;
            p = { a.second, a.first };
            v.push_back(p);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size()-1; i++)
            if(v[i].first == v[i+1].first) return false;
        return true;
    }
};
// @lc code=end

