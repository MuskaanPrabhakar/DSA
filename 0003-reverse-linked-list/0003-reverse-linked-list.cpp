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
    ListNode* reverseList(ListNode* head) {
        // base case
        if (head == nullptr || head->next == nullptr)
            return head;
        
        // reverse the rest
        ListNode* newHead = reverseList(head->next);
        
        // fix current node
        head->next->next = head; // make next node point back to current
        head->next = nullptr;    // break original link
        
        return newHead;
    }
};