/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
     * @brief find the middle and delete it.
     * 
     * @param node the beginning of the ListNode
     * @param len half of the length
     */
    void delete_middle(ListNode* node, int len){
        while(len > 1){
            len--;
            node = node->next;
        }
        node->next = node->next->next;
    }

    /**
     * @brief count the number of the node.
     * 
     * @param node the beginning of the ListNode
     * @return int number of the node.
     */
    int find_len(ListNode* node){
        int len = 0;
        while(node){
            len++;
            node = node->next;
        }
        return len;
    }
    
    ListNode* deleteMiddle(ListNode* head) {
        /**
         * @brief 
         * Solution: 
         * 1. find the len, and cut in half.
         * 2. use the len/2 to find the front of the middle.
         * 3. node->next = node->next->next
         * Status: Accpeted, 1075ms (94.1%), 294.8MB (20.46%)
         */

        int len = find_len(head);
        if(len <= 1) return nullptr;
        delete_middle(head, len/2);
        return head;
    }
};
// @lc code=end

