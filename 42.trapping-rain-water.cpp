/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    
    void LeftToPeak(vector<int>& h, int& w1, int& w2, int& ans, int& peak){
        for(int i = w1+1; i < h.size(); i++){// 移動w2
            if(h[i] >= h[w1]){ w2 = i; break; }
        }
        if(w2 == 0){ // 找不到比w1更高的 -> 找到peak了
            peak = w1;
            return ;
        }
        
        int obstacle = 0; // 找障礙物
        for(int i = w1+1; i < w2; i++) obstacle += h[i];
        
        ans += h[w1]*(w2-w1-1)-obstacle;
        //cout << w1 << " " << w2 << " " << obstacle << ", " << ans << endl;
        
        w1 = w2; w2 = 0; // w1 = w2, w2另外找
        LeftToPeak(h, w1, w2, ans, peak);
    }
    
    void RightToPeak(vector<int>& h, int& w1, int& w2, int& ans, int& peak){
        for(int i = w1-1; i >= peak; i--){// 移動w2
            if(h[i] >= h[w1]){ w2 = i; break; }
        }
        if(w2 == -1)
            return ;
        
        int obstacle = 0; // 找障礙物
        for(int i = w2+1; i < w1; i++) obstacle += h[i];
        
        ans += h[w1]*(w1-w2-1)-obstacle;
        //cout << w1 << " " << w2 << " " << obstacle << ", " << ans << endl;
        
        w1 = w2; w2 = -1; // w1 = w2, w2另外找
        RightToPeak(h, w1, w2, ans, peak);
    }
        
    int trap(vector<int>& h) {
        /* Solution1: Two Pointers
           1. 找左右牆壁(w1,w2) 
           2. 水體積 = min(w1,w2)*(寬度)-(水裡的東西)
           3. 不只找牆壁，還要找山頂(peak)，藉此計算從左&從右到山頂

           Time Complexity: O(n)
           Accepted: 12ms(96.76%), 20.3MB(47.99%)
           
           NOTE:
           function在呼叫value時，盡量使用&，藉此減少記憶體的支出，避免memory limit exceeded
        */
        vector<int> *tmp = new vector<int>;
        *tmp = h;
        sort(tmp->begin(), tmp->end()); // 如果題目從小排到大
        if(*tmp == h) return 0; 
        sort(tmp->rbegin(), tmp->rend()); // 如果題目從大排到小
        if(*tmp == h) return 0;
        delete tmp; // 記得刪掉
        
        int w1 = 0, w2 = 0, peak = 0;
        int ans = 0;
        
        for(int i = 0; i < h.size(); i++){// 初始化w1
            if(h[i] > 0) {w1 = i; break;}
        }
        LeftToPeak(h, w1, w2, ans, peak);
        
        //cout << "Peak=" << peak << endl;
        for(int i = h.size()-1; i >= peak; i--){// 初始化w1
            if(h[i] > 0) {w1 = i; break;}
        }
        if(peak != w1)// peak如果 = 最後一位，則不用進RightToPeak
            RightToPeak(h, w1, w2, ans, peak);
        
        
        return ans;
    }
};
// @lc code=end

