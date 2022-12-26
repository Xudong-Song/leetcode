/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 */

// @lc code=start

//#define SOLUTION1
#define SOLUTION2
class Solution {
private:

#ifdef SOLUTION1
    vector<int> solution1(int n, vector<vector<int>>& edges){
        if(n == 1) return {0};
        vector<int> ans;
        map<int, int> m;
        for(auto e:edges) m[e[1]] = e[0];

        //dist(5, 0, m);
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                if(j != i) sum += dist(i, j, m);
            }
            ans.push_back(sum);
        }
        return ans;
    }

    int dist(int a, int b, map<int, int>& m) {
        int d = 0;
        vector<int> va;
        // cout << a << "," << b << ":";

        while(a != 0) {
            va.push_back(a);
            a = m[a];
            d++;
        }
        vector<int>::iterator it = va.end();
        while(b != 0){
            it = find(va.begin(),va.end(),b);
            if(it != va.end()) break;
            b = m[b];
            d++;
        }
        d -= (va.end() - it);
        // cout << d << "\n";
        return d;
    }
#endif

#ifdef SOLUTION2
    void print_map(vector<vector<int>>& dp, int n = 6){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << dp[i][j];
            }
            cout << endl;
        }
    }

    int dfs(int& a, int& b, map<int, vector<int>>& m, vector<bool>& mark, 
            int dist,  vector<vector<int>>& dp, int& c)
    {                
        // cout << b << "," << n << ":" << dp[n][b] << endl;
        /*if(dp[n][b] != 0){
            return dp[n][b];
        }*/
        if(c == b) {
            dp[a][c] = dist;
            dp[c][a] = dist;
            return dp[a][c];
        }
        mark[c] = true;
        for(auto v:m[c]) {
            if(mark[v] != true) {
                dp[a][v] = dfs(a, b, m, mark, dist+1, dp, v);
                dp[v][a] = dp[a][v];
            }
        }

        mark[c] = false;
        return dist;
    }

    vector<int> solution_2(int n, vector<vector<int>>& edges) {
        vector<int> ans(n, 0);
        map<int, vector<int>> m; 
        vector<bool> mark(n, false);
        
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // make a duplex path.
        for(auto e:edges){
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
        }

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(dp[i][j] != 0) {
                    //tmp = dp[i][j];
                }
                else {
                    dfs(i, j, m, mark, 0, dp, i);
                }
                ans[i] += dp[i][j];
                ans[j] += dp[i][j];
                //cout << "----------\n";
            }
            //cout << "*****************\n";
        }

        print_map(dp, n);

        return ans;
    }
#endif

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
/*
200\n[[18,51],[165,133],[136,133],[126,94],[6,160],[180,17],[71,105],[124,138],[101,32],[155,59],[89,48],[37,110],[70,54],[113,89],[97,42],[69,116],[57,162],[190,132],[8,83],[42,141],[16,141],[102,165],[169,28],[197,93],[126,24],[12,15],[68,43],[16,146],[53,147],[175,198],[187,34],[186,108],[4,11],[175,88],[167,154],[14,98],[142,164],[118,31],[164,108],[160,131],[65,78],[180,127],[66,5],[73,94],[81,42],[7,173],[30,167],[193,64],[140,76],[171,87],[184,131],[28,115],[15,52],[167,131],[151,159],[20,65],[141,58],[46,35],[0,1],[17,182],[99,53],[123,25],[141,147],[44,199],[61,170],[3,139],[171,88],[91,109],[178,144],[135,88],[76,57],[96,187],[129,56],[102,15],[90,18],[96,78],[168,130],[56,132],[164,95],[59,52],[127,120],[4,144],[167,13],[105,174],[149,143],[141,72],[108,41],[10,96],[114,93],[117,78],[84,149],[99,94],[101,163],[43,45],[29,4],[50,134],[104,78],[145,46],[176,139],[85,109],[128,109],[33,12],[21,78],[195,12],[82,49],[143,171],[184,2],[189,104],[47,143],[196,49],[180,191],[60,158],[53,192],[152,70],[80,93],[77,178],[10,22],[64,48],[168,102],[159,92],[49,187],[92,150],[161,194],[132,9],[189,148],[54,185],[168,134],[156,176],[53,164],[60,194],[11,74],[103,147],[37,188],[197,115],[167,8],[122,125],[180,54],[16,25],[31,167],[112,134],[134,179],[38,171],[14,133],[161,70],[26,168],[177,101],[15,96],[71,192],[132,137],[197,180],[55,117],[99,7],[171,42],[5,140],[40,199],[61,78],[77,69],[103,199],[78,53],[28,0],[135,119],[102,132],[172,5],[134,36],[111,58],[166,186],[199,121],[78,180],[143,86],[178,167],[23,167],[180,167],[131,75],[26,110],[39,177],[156,106],[101,165],[105,67],[180,48],[79,167],[147,140],[139,109],[62,134],[51,180],[176,151],[180,176],[100,133],[27,99],[15,153],[45,65],[165,138],[63,15],[168,125],[107,141],[171,183],[46,117],[19,82],[185,157],[42,181]]
*/

#ifdef SOLUTION1
        /**
         * @brief 
         * Solution1: find parent.
         * Wrong Answer: 11/73 cases passed(N/A)
         *               I thought all tree are build as ascending order...
         * 
         */
        return solution1(n, edges);
#endif

#ifdef SOLUTION2
        /**
         * @brief 
         * Solution2: DFS, Dynamic Programming.
         * Time Limit Exceeded: 64/73 cases passed (N/A)
         * Time Complexity: O(n^2)
         * 1. Build the map to imitate the tree.
         * 2. Check the path dist by DFS.
         * 3. Record all path by dp[][]
         * 4. if the nodes have been checked, skip it.
         * 
         * @return return 
         */
        return solution_2(n, edges);
#endif
    }
};
// @lc code=end

