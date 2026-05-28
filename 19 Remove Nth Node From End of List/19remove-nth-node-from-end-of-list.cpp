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
        //O(n) time complexity 2 pass
        // ListNode* prev=head;
        // ListNode* curr=head;
        // int c=0;
        // ListNode* temp=head;
        // while(temp){
        //     c++;
        //     temp=temp->next;
        // }
        // int x=c-n;
        // while(x--){
        //     prev=curr;
        //     curr=curr->next;
        // }
        // if(prev==curr)return nullptr;
        // ListNode* succ=curr->next;
        // prev->next=succ;
        // return head;

        //O(n) time complexity 1 pass
        //. use because dummy create as a object not as a pointer 
        ListNode dummy(0);
        dummy.next=head;
        ListNode* s=&dummy;
        ListNode* f=&dummy;
        for(int i=0;i<n;i++){
            f=f->next;
        }
        while(f->next){
            s=s->next;
            f=f->next;
        }
        s->next=s->next->next;
        return dummy.next;
    }
};