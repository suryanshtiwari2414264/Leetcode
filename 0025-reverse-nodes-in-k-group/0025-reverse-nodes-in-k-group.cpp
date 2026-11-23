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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // step 1 check the length of current group 
        ListNode* temp = head;
        int count =0;
        while(count <k){
            if(temp == NULL){//Base Case
                return head;
            }
            temp = temp->next;
            count ++;
        }
        // Step 2 go ahead for rest of linkedlidt 
        ListNode* prev= reverseKGroup(temp, k);
        // step 3 now reverse the current group and fit 
        temp = head;
        count = 0;
        while(count<k){
           ListNode* NXT = temp->next;
            temp ->next = prev;
            prev = temp;
            temp = NXT;
            count ++;
        }
        return prev;
    }
};