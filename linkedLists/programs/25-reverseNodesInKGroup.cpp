/* 25. Reverse Nodes in k-Group
 *
 * Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
 *
 * k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
 *
 * You may not alter the values in the list's nodes, only nodes themselves may be changed.
 *
 * Example 1:
 *
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 *
 * Example 2:
 *
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* temp = head;
        int count = 0;

        // check if k nodes exist
        while (count < k) {
            if (temp == nullptr) {
                return head;
            }
            temp = temp->next;
            count++;
        }

        ListNode* prev = reverseKGroup(temp, k);

        temp = head;
        count = 0;

        // reverse the ll until k
        while (count < k) {
            ListNode* next = temp->next;
            temp->next = prev;

            prev = temp;
            temp = next;
            count++;
        }
        return prev;
    }
};
