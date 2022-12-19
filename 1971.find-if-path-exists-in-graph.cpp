/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start
/*
10\n[[0,7],[0,8],[6,1],[2,0],[0,4],[5,8],[4,7],[1,3],[3,5],[6,5]]\n7\n5
*/
class Solution {
public:
    void find_path(int n, map<int, vector<int>>& m, int& s, int& d, 
                                    bool& ans, map<int, bool>& mark) {
        // 3. The max move is n, therefore, we should not move more than n step.
        if(n == 0) return ;

        // 2. Mark the node just passed.
        mark[s] = true;

        for(auto a:m[s]){
            if(a == d) ans = true;
            else if(mark[a] != true) {
                // 2. Mark the node just passed, and move to next step.
                // cout << n << ", " << s << ":" << a << endl;
                mark[a] = true;
                find_path(n-1, m, a, d, ans, mark);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        /**
         * @brief 
         * Solution: DFS (that is eazy?)
         * Time Complexity: 
         * Accepted: 1875ms(10.79%), 306.4MB(5.07%)
         * 0. Make a graph, whick has all connect nodes and mark colors.
         * 1. Start from the s, find all connect node.
         * 2. Mark the node just passed, and move to next step.
         * 3. The max move is n, therefore, we should not move more than n step.
         * 
         */
        bool ans = false;

        if(edges.size() == 0) return true;

        map<int, vector<int>> m;
        map<int, bool> mark;

        // 0. Make a graph.
        for(auto e:edges){ //O(n)
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
            mark[e[0]] = false;
            mark[e[1]] = false;
        }
        // 1. Start from the s, find all connect node.
        find_path(n, m, s, d, ans, mark);
        return ans;
    }
    

};
// @lc code=end

