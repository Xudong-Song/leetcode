/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        /* 
         * Solution1: Two Pointer, Space Complexity O(1), Time Complexity O(n)
         *            Accepted, 20ms(37.36%), 7.7MB(38.21%)
         *
         * 1. Two Pointer: Fast (move 2 step), Slow (move 1 step)
         * 2. Consider the Fast is running as 1 step per time, and Slow is stop.
         *    Everytime when Fast complete the whole length, Slow will move 1 step.
         *    Therefore, we can check the whole list to find which is the target.
         * 3. Now consider if the list is a cycle, we cannot find the end of the list,
         *    therefore, the Slow needs to move as 1 step, and the Fast need to move
         *    1 step faster Slow, and they will meet each other at the least common 
         *    multiple, which is the beginning of the list.
         * 4. Now consider if the list has a tail at the beginning, and the length is 
         *    X, and the cycle lenght is Y. It means Fast will be X%Y when Slow reach
         *    the cycle, and Fast and Slow will meet each other at Y-X because the tail
         *    is not the part of the cycle, and we need to fix by moving Slow X time.
         * 5. X is not the given value, however, we can use head and Slow to check the
         *    beginning of the cycle.
         * 6. The least common multiple of Fast and Slow is 2n, we should move 2n time 
         *    to get the answer, so the Time Complexity is O(n)
         * 
         * Solution2: Save all Node, and check if any node is repeated. 
         *            Space Complexity O(n), Time Complexity O(n). (Doesn't implement)
         */

        if(!head) return nullptr;

        //1.
        ListNode *fast = head;
        ListNode *slow = head;

        //2.3.4.
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            //cout << slow->val << ", " << fast->val << endl;
            if(fast == slow) break;
        }

        if(!fast || !fast->next){
            return nullptr;
        }

        //5.
        while(head != slow){
            head = head->next;
            slow = slow->next;
        }

        return head;

    }
};
// @lc code=end

