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
    bool isPalindrome(ListNode* head) {
        vector<int>arr;
        while(head!=NULL){
            arr.push_back(head->val);
            head= head->next;
        }
        int n = arr.size();
        int i = 0,j=n-1;
        while(i<j){
            if(arr[i]!=arr[j])
                return false;
            else{
                i++;
                j--;
            }
        }
        return true;
        
    }
};