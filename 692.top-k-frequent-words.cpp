/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        vector<string> ans;

        for(auto w:words){
            if(m.find(w) != m.end()){
                m[w]++;
            }else{
                m[w] = 1;
            }
        }

        for(auto it:m){
            if(it.second == 2){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
// @lc code=end

