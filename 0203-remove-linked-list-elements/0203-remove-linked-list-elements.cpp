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
 // RECURSIVE APPROACH
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         if(head == NULL)
//             return NULL;
//         head->next = removeElements(head->next,val);
//         return head->val == val ? head->next : head;
        
//     }
// };

// 2nd Approach 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // Remove matching nodes from the beginning
        while(head != NULL && head->val == val)
        {
            head = head->next;
        }

        if(head == NULL)
            return NULL;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr != NULL)
        {
            if(curr->val == val)
            {
                prev->next = curr->next;
            }
            else
            {
                prev = curr;
            }

            curr = curr->next;
        }

        return head;
    }
};