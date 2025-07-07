/* 19. Remove Nth Node From End Of List
 *
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 *
 * Example 1:
 *
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 * Example 2:
 *
 * Input: head = [1], n = 1
 * Output: []
 *
 * Example 3:
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* first = dummy;
        ListNode* second = dummy;

        for (int i = 0; i <= n; ++i) {
            second = second->next;
        }

        while (second != nullptr) {
            first = first->next;
            second = second->next;
        }

        ListNode* temp = first->next;
        first->next = first->next->next;
        delete temp;

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};
