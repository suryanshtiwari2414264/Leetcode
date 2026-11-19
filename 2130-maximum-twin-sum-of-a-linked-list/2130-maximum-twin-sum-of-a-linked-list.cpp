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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast ->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = slow;
        slow = slow->next;
        prev->next=NULL;
        while(slow!=NULL){
            ListNode* temp = slow->next;
            slow->next =  prev;
            prev=slow;
            slow=temp;
        }
        int sum = INT_MIN;
        int max_sum = 0;
        ListNode* p1 = head;
        ListNode* p2 = prev;
        while(p2 != NULL){
            sum = (p1->val)+(p2->val);
            max_sum = max(max_sum,sum);
            p1 = p1->next;
            p2 = p2->next;
        }
        return max_sum;
    }
};