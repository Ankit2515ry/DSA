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
        //O(n) time and space complexity
        // ListNode* s=head;
        // ListNode* f=head;
        // stack<int>st;
        // while(f){
        //     int x=k;
        //     while(f&&x--){
        //         st.push(f->val);
        //         f=f->next;
        //     }
        //     x=k;
        //     while(f&&x--){
        //         s->val=st.top();
        //         st.pop();
        //         s=s->next;
        //     }
        // }
        // return head;

        //O(n) time complexity O(1) space complexity
        if(!head||!head->next||k<=1)return head;
        ListNode dummy(0);
        dummy.next=head;
        ListNode* pge=&dummy;
        while(true){
            ListNode* kth=pge;
            for(int i=0;i<k&&kth;i++){
                kth=kth->next;
            }
            if(!kth)break;
            ListNode* gs = pge->next;
            ListNode* ng = kth->next;
            ListNode* curr=gs;
            ListNode* prev=ng;
            while(curr!=ng){
                ListNode* n=curr->next;
                curr->next=prev;
                prev=curr;
                curr=n;
            }
            pge->next=kth;
            pge=gs;
        }
        return dummy.next;
    }
};