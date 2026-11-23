// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
//     int GCD(int a,int b)
//     {
//         int n=min(a,b);
//         int gcd;
//         for(int i=n;i>=1;i--)
//         {
//             if(a%i==0 && b%i==0){
//                 gcd=i;
//                 break;
//             }
//         }
//         return gcd;
//     }
// public:
//     ListNode* insertGreatestCommonDivisors(ListNode* head) {
//         ListNode* temp=head;
//         while(head!=0 && head->next!=NULL)
//         {
//             ListNode* node=new ListNode();
//             node->val=GCD(head->val,head->next->val);
//             node->next=head->next;
//             head->next=node;
//             head=node->next;
//         }
//         return temp;
//     }
// };

class Solution {
public:
    int gcd(int a, int b){
        if(b==0)
            return a;
        else
            return gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        //EDGE CASES
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* curr = head;
        while(curr && curr->next){
            int val = gcd(curr->val,curr->next->val);
            ListNode* newNode = new ListNode(val);
            // fit new node after curr
            newNode ->next = curr->next;
            curr-> next = newNode;
            curr = newNode-> next;
        } 
        return head;
    }
};