/* 203. Remove Linked List Elements
 *
 * Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
 *
 * Example 1:
 *
 * Input: head = [1,2,6,3,4,5,6], val = 6
 * Output: [1,2,3,4,5]
 *
 * Example 2:
 *
 * Input: head = [], val = 1
 * Output: []
 *
 * Example 3:
 *
 * Input: head = [7,7,7,7], val = 7
 * Output: []
 *
 */

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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = dummy;

        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
