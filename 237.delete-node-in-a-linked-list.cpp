/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
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
    void deleteNode(ListNode* node) {
        /**
         * @brief  Can not delete the node directly, therefore, we can copy
         *         the value of each node behind, then delete the last node.
         */

        cout << node->val << endl;
        
        if(!node)
        {
            return ;
        }
        
        node->val = node->next->val;
        if(node->next->next == NULL)
        {
            node->next = node->next->next;
        }

        else
        {
            deleteNode(node->next);
        }
    }
};

// @lc code=end

