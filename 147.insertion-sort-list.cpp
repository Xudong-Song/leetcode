/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    /**
     * @brief check and insert the node into ans list.
     * 
     * @param ans the answer list
     * @param tmp a node of the given list.
     */
    void solve(ListNode* ans, ListNode* tmp)
    {
        while(ans)
        {
            // if it is the end of the list, append the node.
            if(!ans->next && ans->val <= tmp->val)
            {
                ans->next = tmp;
                tmp->next = nullptr;
                return ;
            }
            // if it is not the end of the list, insert the node.
            else if(ans->val <= tmp->val && ans->next->val >= tmp->val)
            {
                ListNode* tmp_ans_next = ans->next;
                ans->next = tmp;
                tmp->next = tmp_ans_next;
                return ;
            }
            // check next node.
            else
            {
                ans = ans->next;
            }
        }
    }

    ListNode* insertionSortList(ListNode* head) 
    {
        /* 
         * Solution: ...Well, it's a insertion Sort, but not as same as the example.
         *           Accepted, 50ms(56.52%), 10.1MB(8.65%)
         * 
         * 1. Store the first node into ans list.
         * 2. Check the ans list from the beginning.
         * 3. Insert the next node within.
         * 
         */
        
        ListNode* ans = new ListNode(-2147483647);
        while(head)
        {
            ListNode* tmp = new ListNode(head->val);
            if(ans->next) solve(ans, tmp);
            else ans->next = tmp;
            head = head->next;
        }

        return ans->next;
    }
};
// @lc code=end

