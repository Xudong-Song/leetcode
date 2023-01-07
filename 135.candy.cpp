/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
public:
    void add_one(vector<int>& ratings, vector<int>& tmp, int& peak, int& index){
        while(index < ratings.size()-1){
            if(ratings[index] <= ratings[index+1]){
                break;
            }
            index++;
            //cout << "AAA";
        }
        for(int i = index-1; i > peak; i--){
            tmp[i] = tmp[i+1]+1;
        }
        if(tmp[peak] <= tmp[peak+1]){
            tmp[peak] = tmp[peak+1] + 1;
        }
        
        /* 
        ************* Solution1 *************
        for(int i = peak; i < index; i++)
            if(tmp[i] <= tmp[i+1]+1) 
                tmp[i]++;
                
        ************* Solution1 *************
        */
    }
    
    int candy(vector<int>& ratings) {
        /*
            Solution1: 
                1. 設定一個Peak，代表範圍內最高分的人
                2. 全部小孩都從1開始
                3. 如果下一個小孩>自己，下一個小孩=自己+1
                4. 檢查下一個人有沒有比自己低分，有的話從Peak開始到目前的小孩全部+1
                5. Peak移動方式: 如果下一個>=自己，則Peak往後移
                
                Status: TLE
                Time Complexity: O(n^2)
                
            Solution2:
                Optimize: 如果發現降序(Descending)的字串，此字串必為相差為1的降序，因此可以直接付值，不用逐個判斷
                           ex: 10, 8, 2, 0
                          ans:  4 + 3 + 2 + 1 = 10
                Status: Accepted, 31ms(70.08%), 17.7MB(63.55%) 
                Time Complexity: O(n)
        */
        
        int peak = 0; // 1.
        vector<int> tmp(ratings.size(), 1); // 2.
        
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] >= ratings[i-1]){ // 5.
                if(ratings[i] > ratings[i-1]) tmp[i] = tmp[i-1]+1; // 3.
                peak = i; 
            }else // 4.
                if(tmp[i-1] == 1) add_one(ratings, tmp, peak, i);
            /*
            for(int j = 0; j < tmp.size(); j++){
                cout << tmp[j] << ",";
            }cout << endl;*/
        }
        
        int ans = 0;
        for(int i = 0; i < tmp.size(); i++) ans+=tmp[i];
        
        return ans;
    }
};
// @lc code=end

