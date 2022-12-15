/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start

//#define SOLUTION_1
#define SOLUTION_2 // Optimized Space solution

// ""abcba"\n"abcbcba""
// ""bsbininm"\n"jmjkbkjkv""
class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
#ifdef SOLUTION_1
        /**
         * @brief 
         * Solution: Dynamic Programming.
         * Time Complexity: O(n*m)
         * Space Complexity: O(n*m)
         * Accepted: 17ms(86.03%), 12.9MB(63.56%)
         * 1. Init the dp map as 0
         * 2. When we get the char consist with the target, we should refer to
         *    the value which record by the pervious char, then add one. 
         *    => m[i][j] = m[i-1][j-1]+1
         * 3. If we the char doesn't consist with the target, refer to the
         *    value record before.
         *    => m[i][j] = max(m[i-1][j], m[i][j-1])
         * 4. The answer should be the buttom-right one.
         */

        // use new to creat a 2D matrix.
        int **m = new int*[t2.size()+1]; // t2 is the height of the matrix
        for(int i = 0; i < t2.size()+1; i++)
            m[i] = new int[t1.size()+1]{}; // t1 is the width of the matrix
        
        for(int i = 1; i < t2.size()+1; i++){
            for(int j = 1; j < t1.size()+1; j++){
                if(t1[j-1]==t2[i-1]) m[i][j] = m[i-1][j-1]+1;
                else m[i][j] = max(m[i-1][j], m[i][j-1]);
                //cout << m[i][j] << t1[j-1] << t2[i-1] << ",";
            }
            //cout << endl;
        }
        return m[t2.size()][t1.size()];
#endif

#ifdef SOLUTION_2
        /**
         * @brief 
         * Solution2: Same as Solution1, but Optimized Memory Solution
         * Accepted: 18ms(84.85%), 6.5MB(91.51%)
         * Time Complexity: O(n*m)
         * Space Complexity: O(n)
         * 1. Because we only look up above line, we can update the first 
         *    line instead of record the whole dp map.
         */

        // use new to creat a 2D matrix.
        int **m = new int*[2];
        m[0] = new int[t1.size()+1]{};
        m[1] = new int[t1.size()+1]{};

        for(int i = 1; i < t2.size()+1; i++){
            for(int j = 1; j < t1.size()+1; j++){
                m[0][j] = m[1][j];
                if(t1[j-1]==t2[i-1]) m[1][j] = m[0][j-1]+1;
                else m[1][j] = max(m[0][j], m[1][j-1]);
                //cout << m[1][j] << t1[j-1] << t2[i-1] << ",";
            }
            //cout << endl;
        }
        return m[1][t1.size()];
#endif
    }
};
// @lc code=end

