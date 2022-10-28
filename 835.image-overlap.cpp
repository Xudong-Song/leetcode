/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// @lc code=start
class Solution {
public:

    /**
     * @brief Calculate the overlap
     * 
     * @param img1 changed img1
     * @param img2 origin img2 from the question
     * @param ans number of the overlap
     * @param n size of the img
     */
    void calculate(vector<vector<int>>& img1, vector<vector<int>>& img2, int& ans, int& n){
        int ans_tmp = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(img1[i][j] == 1 && img2[i][j] == 1)
                    ans_tmp++;
        if(ans < ans_tmp)
            ans = ans_tmp;
    }

    /**
     * @brief move the img1 "up" and retrun the img
     * 
     * @param img1 change img1
     * @param img2 origin img2 from the question
     * @param ans number of the overlap, only use at calculate function
     * @param n size of the img
     * @return vector<vector<int>> 
     */
    vector<vector<int>> up(vector<vector<int>>& img1, vector<vector<int>>& img2, int& ans, int& n){
        vector<vector<int>> img_tmp;
        for(int i = 0; i < n; i++){
            vector<int> tmp;
            for(int j = 0; j < n; j++){
                if(i == n-1){
                    tmp.push_back(0);
                }else{
                    tmp.push_back(img1[i+1][j]);
                }
            }
            img_tmp.push_back(tmp);
        }
        calculate(img_tmp, img2, ans, n);
        return img_tmp;
    }

    /**
     * @brief move the img1 "down" and retrun the img
     * 
     * @param img1 change img1
     * @param img2 origin img2 from the question
     * @param ans number of the overlap, only use at calculate function
     * @param n size of the img
     * @return vector<vector<int>> 
     */
    vector<vector<int>> down(vector<vector<int>>& img1, vector<vector<int>>& img2, int& ans, int& n){
        vector<vector<int>> img_tmp;
        for(int i = 0; i < n; i++){
            vector<int> tmp;
            for(int j = 0; j < n; j++){
                if(i == 0){
                    tmp.push_back(0);
                }else{
                    tmp.push_back(img1[i-1][j]);
                }
            }
            img_tmp.push_back(tmp);
        }
        calculate(img_tmp, img2, ans, n);
        return img_tmp;
    }

    /**
     * @brief move the img1 "right" and retrun the img
     * 
     * @param img1 change img1
     * @param img2 origin img2 from the question
     * @param ans number of the overlap, only use at calculate function
     * @param n size of the img
     * @return vector<vector<int>> 
     */
    vector<vector<int>> right(vector<vector<int>>& img1, vector<vector<int>>& img2, int& ans, int& n){
        vector<vector<int>> img_tmp;
        for(int i = 0; i < n; i++){
            vector<int> tmp;
            for(int j = 0; j < n; j++){
                if(j == 0){
                    tmp.push_back(0);
                }else{
                    tmp.push_back(img1[i][j-1]);
                }
            }
            img_tmp.push_back(tmp);
        }
        calculate(img_tmp, img2, ans, n);
        return img_tmp;
    }

    /**
     * @brief move the img1 "left" and retrun the img
     * 
     * @param img1 change img1
     * @param img2 origin img2 from the question
     * @param ans number of the overlap, only use at calculate function
     * @param n size of the img
     * @return vector<vector<int>> 
     */
    vector<vector<int>> left(vector<vector<int>>& img1, vector<vector<int>>& img2, int& ans,  int& n){
        vector<vector<int>> img_tmp;
        for(int i = 0; i < n; i++){
            vector<int> tmp;
            for(int j = 0; j < n; j++){
                if(j == n-1){
                    tmp.push_back(0);
                }else{
                    tmp.push_back(img1[i][j+1]);
                }
            }
            img_tmp.push_back(tmp);
        }
        calculate(img_tmp, img2, ans, n);
        return img_tmp;
    }

    /**
     * @brief print the matrix
     * 
     * @param img img that wants to print
     * @param n size of the img
     */
    void print_matirx(vector<vector<int>>& img, int& n){
        cout << endl;
        for(int i = 0; i < n; i++){
            cout << endl;
            for(int j = 0; j < n; j++){
                cout << img[i][j] << ",";
            }
        }
    }

    /**
     * @brief move to the first_phase (right, up)
     * 
     * @param img1 origin img1 from the question
     * @param img2 origin img2 from the question
     * @param ans number of the overlap, only use at calculate function
     * @param n size of the img
     */
    void first_phase(vector<vector<int>>& img1, vector<vector<int>>& img2, int& ans, int& n)
    {
        /*right(img1, img2, ans, n);
        up(img1, img2, ans, n);*/

        vector<vector<int>> img_r;
        img_r = img1;
        for(int i = 0; i < n-1; i++){
            img_r = right(img_r, img2, ans, n);
            vector<vector<int>> img_d;
            img_d = img_r;
            for(int j = 0; j < n-1; j++){
                //print_matirx(img_d, n);
                img_d = up(img_d, img2, ans, n);
            }
        }
    }

    /**
     * @brief move to the second_phase (left, up)
     * 
     * @param img1 origin img1 from the question
     * @param img2 origin img2 from the question
     * @param ans number of the overlap, only use at calculate function
     * @param n size of the img
     */
    void second_phase(vector<vector<int>>& img1, vector<vector<int>>& img2, int& ans, int& n)
    {
        /*left(img1, img2, ans, n);
        up(img1, img2, ans, n);*/

        vector<vector<int>> img_r;
        img_r = img1;
        for(int i = 0; i < n-1; i++){
            img_r = up(img_r, img2, ans, n);
            vector<vector<int>> img_d;
            img_d = img_r;
            for(int j = 0; j < n-1; j++){
                //print_matirx(img_d, n);
                img_d = left(img_d, img2, ans, n);
            }
        }
    }

    /**
     * @brief move to the third_phase (left, down)
     * 
     * @param img1 origin img1 from the question
     * @param img2 origin img2 from the question
     * @param ans number of the overlap, only use at calculate function
     * @param n size of the img
     */
    void third_phase(vector<vector<int>>& img1, vector<vector<int>>& img2, int& ans, int& n)
    {
        /*left(img1, img2, ans, n);
        down(img1, img2, ans, n);*/

        vector<vector<int>> img_r;
        img_r = img1;
        for(int i = 0; i < n-1; i++){
            img_r = left(img_r, img2, ans, n);
            vector<vector<int>> img_d;
            img_d = img_r;
            for(int j = 0; j < n-1; j++){
                //print_matirx(img_d, n);
                img_d = down(img_d, img2, ans, n);
            }
        }
    }

    /**
     * @brief move to the forth_phase (right, down)
     * 
     * @param img1 origin img1 from the question
     * @param img2 origin img2 from the question
     * @param ans number of the overlap, only use at calculate function
     * @param n size of the img
     */
    void forth_phase(vector<vector<int>>& img1, vector<vector<int>>& img2, int& ans, int& n)
    {
        vector<vector<int>> img_r;
        img_r = img1;
        for(int i = 0; i < n-1; i++){
            img_r = down(img_r, img2, ans, n);
            vector<vector<int>> img_d;
            img_d = img_r;
            for(int j = 0; j < n-1; j++){
                //print_matirx(img_d, n);
                img_d = right(img_d, img2, ans, n);
            }
        }
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        /**
         * @brief 
         * Solution1: Move the img1 driectly
         * 1. tree: many duplicate results, time complexity = O(2^n)
         * 2. matrix: (1) TLE, 58/59 cases passed (N/A)
         *            (2) Accepted, 2260ms(5.56%), 527.9MB(6.94%) -> Doesn't change anything, 
         *                but it just accecpted. (only one time)
         *            because the duplicate result is in a predictable range, 
         *            we should just compute the possible result instead of moving it in real way. 
         *            It cost 2N+2 to move horizontal, and 2N+2 to move vertical.
         *            And when we want to calculate the ans, it cost n^2.
         *            Therefore, the time complexity is O(n^4).
         *            It cost a lots of time, and it seems cost a lots of space.
         * 
         * 
         */
        int ans = 0;
        int n = img1.size();
        // calculate the origin 
        calculate(img1, img2, ans, n);
        //cout << ans << endl;
        //cout << "first phase";
        first_phase(img1, img2, ans, n);
        //cout << ans << endl;
        //cout << "\n\nsecond phase";
        second_phase(img1, img2, ans, n);
        //cout << ans << endl;
        //cout << "\n\nthird phase";
        third_phase(img1, img2, ans, n);
        //cout << ans << endl;
        //cout << "\n\nforth phase";
        forth_phase(img1, img2, ans, n);
        //cout << ans << endl;


        return ans;
    }
};
// @lc code=end

