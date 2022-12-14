/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        /**
         * @brief 
         * Solution: Split the List into pieces then combine then with
         *           ascending order.
         * Time Complexity: O(nlogn)
         * Accepted: 202ms(94.4%), 60.2MB(50.49%)
         * 1. Store the value of all node -> O(n)
         * 2. Sort -> O(nlogn)
         * 3. Chain the node with ascending order -> O(n)
         * 
         */
        if(!head) return head;

        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }

        sort(v.begin(), v.end());

        ListNode* tmp = new ListNode;
        ListNode* ans = tmp;
        for(int i = 0; i < v.size(); i++){
            tmp->val = v[i];
            if(i != v.size()-1){
                ListNode* tmp_next = new ListNode;
                tmp->next = tmp_next;
                tmp = tmp->next;
            }
        }

        return ans;
    }
};
// @lc code=end

