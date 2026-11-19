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
// TWO REVERSAL APPROACH
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        // ListNode* dummy=new ListNode(-1);
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr!= NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        // ListNode* dummy=new ListNode(-1);
        ListNode* curr = head;
        ListNode* prev = head;
        while(curr !=NULL){
            if(curr->val >= prev->val){
                prev = curr;
                curr = curr->next;
            }
            else{
                prev->next = curr->next;
                curr = curr->next;
            }
        }
        head = reverse(head);
        return head;
    }
};

// class Solution {
// public:
//         ListNode* removeNodes(ListNode* head){
//             stack<ListNode*> st;
//             ListNode* curr = head;
//             while(curr){
//                 st.push(curr);
//                 curr = curr->next;
//             }
//             int curr_max = INT_MIN;
//             ListNode* result = NULL;
//             while(!st.empty()){
//                 curr = st.top();
//                 st.pop();
//                 if(curr->val >= curr_max){
//                     curr->next = result;
//                     result = curr;
//                     curr_max = curr->val;
//                 }
//             }
//             return result;
//         }
// };