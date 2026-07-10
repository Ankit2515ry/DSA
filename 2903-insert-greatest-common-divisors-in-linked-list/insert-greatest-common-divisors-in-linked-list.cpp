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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr=head;
        ListNode* next=head->next;
        while(next!=nullptr){
            int a=curr->val;
            int b=next->val;
            int v=gcd(a,b);
            ListNode* temp=new ListNode(v);
            curr->next=temp;
            temp->next=next;
            curr=next;
            next=next->next;
        }
        return head;
    }
};