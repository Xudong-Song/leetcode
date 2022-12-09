/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        /**
         * @brief 
         * Solution: Move all even nodes to the end of the list. 
         * Time Complexity:  O(n), Find last first: O(n), then go through the 
         *                   whole list: O(1/2n), the Time Complexity should 
         *                   be O(3/2n) = O(n).
         * Space Complexity: O(1), Only use 3 node (ans, last, tmp) for this 
         *                   solution. Every time when system find even node,
         *                   use tmp to save the number, and append it to the
         *                   end of the list.
         * Accepted: 16ms(75.16%), 10.8MB(5.22%)
         */
        if(!head) return head;
        int len = 1;
        ListNode* ans = head;
        ListNode* last = head;
        while(last->next){ //O(n) 
            last = last->next;
            len++;
        }

        for(int i = 1; i < len; i++){ // O(1/2n)
            // Move Even Node to the end of the list.
            ListNode* tmp = new ListNode;
            tmp->val = head->next->val;
            last->next = tmp;
            last = last->next;
            
            // Skip Even node
            head->next = head->next->next;
            head = head->next;
            i++;
        }

        return ans;
    }
};
// @lc code=end

