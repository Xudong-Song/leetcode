/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void swap(vector<ListNode*>& tmp, int head, int tail){
        if(head == tail) {
            tmp[head]->next = nullptr;
        }
        else if(tail - head == 1){
            tmp[head]->next = tmp[tail];
            tmp[tail]->next = nullptr;
        }
        else{
            tmp[head]->next = tmp[tail];
            head++;
            tmp[tail]->next = tmp[head];
            tail--;
            swap(tmp, head, tail);
        }
    }

    void reorderList(ListNode* head) {
        vector<ListNode*> tmp;
        while(head){
            tmp.push_back(head);
            head = head->next;
        }
        swap(tmp, 0, tmp.size()-1);
    }
};
// @lc code=end

