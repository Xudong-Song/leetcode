/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution {
public:

    /**
     * @brief Make a gene map to check the possiblity of mutation.
     * 
     * @param s key gene.
     * @param b gene bank.
     * @return vector<string> all possiblity of the key gene.
     */
    vector<string> mutation_able(string& s, vector<string>& b){
        vector<string> mutation;
        for(string m:b){
            int dif = 0;
            for(int i = 0; i < 8; i++) if(s[i] != m[i]) dif++;
            if(dif == 1) mutation.push_back(m);
        }
        return mutation;
    }

    /**
     * @brief Backtracking, trying all possiblity to get the min step of mutation.
     * 
     * @param ans the min step to move from start to end.
     * @param count step of this path.
     * @param start the gene right now.
     * @param end the target gene.
     * @param b_map the possible mutation of all gene in bank.
     */
    void mutation(int& ans, int count, string start, string end,
    map<string, pair<vector<string>,bool>> b_map)
    {
        // mark it when it has been run.
        b_map[start].second = true;

        // check if it is the anwser.
        if(start == end) {
            // find the small one.
            ans = min(ans,count);
            return ;
        }
        
        // every time when we get into the recursive, count++ 
        // (like a tree level, when we move to the next level, we plus one)
        count++;

        // run all possible mutate of this gene.
        for(auto b:b_map[start].first){
            // only run the un-marked one.
            if(b_map[b].second == false){
                // recursive
                mutation(ans, count, b, end, b_map);
    }

    int minMutation(string start, string end, vector<string>& bank) {
        /**
         * @brief 
         * The Question is to check how many time will start gene mutation validly to become end gene.
         * 
         * Therefore, we can mutation the start gene into bank gene until the gene is consist with end,
         * and count the number of mutations time.
         * 
         * Because we can only mutation a bit of gene once a time, we should check the bank gene and get 
         * the nubmer of difference.
         * 
         * And we might check the difference of each gene in bank, only can mutation when the difference
         * is one.
         * 
         * Solution: Backtracking. (Don't have any other idea.)
         *           Accepted, 3ms(45.67%), 7.8MB(7.33%)
         * 
         * 
         */
        int ans = 11;

        // possibility of start.
        map<string, vector<string>> s_map;
        s_map[start] = mutation_able(start, bank);

        // possibility of all gene in bank.
        map<string, pair<vector<string>,bool>> b_map;
        for(auto b:bank){ 
            b_map[b].first = mutation_able(b, bank);
            b_map[b].second = false;
        }

        // start to mutate, count += 1
        for(auto s:s_map[start]) mutation(ans, 1, s, end, b_map);
        
        // because the maximun of bank size is 10, the max possible answer is 10. 
        if(ans == 11) return -1;
        else return ans;
    }
};


// @lc code=end

