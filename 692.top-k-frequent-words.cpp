/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        /**
         * @brief 
         * Solution: Count the number of occurrences of all words, and build a hash table to get the answer.
         * Accepted, 23ms(68.21%), 12.7MB(58.03%)
         * 1. Have no idea to store the data into map and increase the key value by their occurrences times.
         * 2. Therefore, we build another map to get the the frequency of data. Although it spend more space, it works.
         * 
         */
        map<string, int> m;
        map<int, vector<string>> m2;
        vector<string> ans;

        // Count the number of occurrences of all words, and store it into map (can use 2-D array instead).
        for(auto w:words) {
            if(m.find(w) != m.end()) m[w]++;
            else m[w] = 1;
        }

        // map will sort the data by their first value, we can use this feature to get the answer.
        for(auto it:m) {
            m2[it.second].push_back(it.first);
        }
        
        // map is Ascending Order, therefore, we need to get the data behind.
        // -> use "reverse_iterator" instead of "iterator".
        int counter = 0;
        for(map<int, vector<string>>::reverse_iterator it = m2.rbegin(); it != m2.rend(); it++) {
            for(int i = 0; i < it->second.size(); i++) {
                //cout << it->first << ":" << it->second[i] << endl;
                ans.push_back(it->second[i]);
                counter++;
                if(counter >= k) return ans;
            }
        }

        return ans;
    }
};
// @lc code=end

