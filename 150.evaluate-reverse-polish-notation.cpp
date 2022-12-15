/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:

    void set_v1_v2(long long int& v1, long long int& v2, 
                                stack<long long int>& s) {
        v1 = s.top();
        s.pop();
        v2 = s.top();
        s.pop();
    }

    int evalRPN(vector<string>& tokens) {
        /**
         * @brief 
         * Solution: Stack
         * Time Complexity: O(n)
         * Accepted: 10ms(92.18%), 12.2MB(52.34%)
         * 1. Record all string into stack.
         * 2. when the string is not a integer, calcuate the top two 
         *    numbers of stack with the specified operator, and push
         *    the answer back into the stack.
         *    
         * Blind Point: 1. We need to push the value back into the 
         *                 stack.
         *              2. The function of stack "top" is pass by
         *                 reference.
         * 
         */
        stack<long long int> s;
        for(auto t:tokens){
            long long int v1 = 0;
            long long int v2 = 0;
            if(t == "+"){
                set_v1_v2(v1,v2,s);
                s.push(v2+v1);
            }else if(t == "-"){
                set_v1_v2(v1,v2,s);
                s.push(v2-v1);
            }else if(t == "*"){
                set_v1_v2(v1,v2,s);
                s.push(v2*v1);
            }else if(t == "/"){
                set_v1_v2(v1,v2,s);
                s.push(v2/v1);
            }else {
                s.push(stoi(t));
            }
        }
        return s.top();
    }
};
// @lc code=end

