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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Create a dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches NULL
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Node to be deleted
        ListNode* temp = slow->next;

        // Remove the node
        slow->next = temp->next;

        // Free memory
        delete temp;

        // Store new head
        ListNode* newHead = dummy->next;

        // Delete dummy node
        delete dummy;

        return newHead;
    }
};