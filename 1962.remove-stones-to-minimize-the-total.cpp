/*
 * @lc app=leetcode id=1962 lang=cpp
 *
 * [1962] Remove Stones to Minimize the Total
 */

// @lc code=start

#define SOLUTION2
#define OPTIMIZED

class Solution {
private:
    int find_largest(vector<int>& p) {  
        int max = 0;
        int index = 0;
        for(int i = 0; i < p.size(); i++){
            if(p[i] > max){
                max = p[i];
                index = i;
            }
        }
        return index;
    }

public:
    int minStoneSum(vector<int>& p, int k) {
        /**
         * @brief 
         * Solution1: Use Sort function
         *            Time Complexity: O(k*nlogn + n), n=p.size
         *            TLE: 35/59 cases passed (N/A)
         * 
         * Optimized: 
         * 1. find the biggest k number instead of using sort function.
         *            Time Complexity: O(k*n + n)
         *            TLE: 45/59 cases passed (N/A)
         * 
         * Solution2: Use Max Heap instead of Sort
         *            Time Complexity: O(k*logn)
         *            Accepeted: 526ms(95%), 98.9MB(84.14%)
         *    
         */

#ifndef SOLUTION2
        while(k > 0){
            k--;
            #ifndef OPTIMIZED   //O(k*nlogn)
                sort(p.rbegin(), p.rend());
                p[0] -= p[0]/2;
            #else               //O(k*n)
                int i = find_largest(p);
                p[i] -= p[i]/2;
            #endif
        }        
        int ans = 0;
        for(int i = 0; i < p.size(); i++){ //O(n)
            ans+=p[i];
        }
        return ans;
#else
        priority_queue<int> heap(p.begin(), p.end());
        int totalSum = accumulate(p.begin(), p.end(), 0);
        
        for (int i = 0; i < k; i++) {
            int curr = heap.top();
            heap.pop();
            int remove = curr / 2;
            totalSum -= remove;
            heap.push(curr - remove);
        }
        
        return totalSum;
#endif
    }
};
// @lc code=end

