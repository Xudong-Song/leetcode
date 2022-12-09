/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    ListNode* middleNode(ListNode* head) {
        int len = 1;
        ListNode* tmp = head;
        while(tmp->next){
            tmp = tmp->next;
            len++;
        }
        if(len%2 == 0) len++;
        for(int i = 0; i < len/2; i++) head = head->next;
        return head;
    }
};
// @lc code=end

