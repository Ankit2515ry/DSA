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
        //O(n) time and space complexity
        // stack<ListNode*>st;
        // ListNode* s=head;
        // ListNode* f=head;
        // while(f&&f->next){
        //     s=s->next;
        //     f=f->next->next;
        // }
        // while(s){
        //     st.push(s);
        //     s=s->next;
        // }
        // s=head;
        // while(!st.empty()){
        //     if(st.top()->val!=s->val)return false;
        //     st.pop();
        //     s=s->next;
        // }
        // return true;

        ListNode* s=head;
        ListNode* f=head;
        while(f&&f->next){
            s=s->next;
            f=f->next->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = s;
        while(curr){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        s=head;
        f=prev;
        while(s&&f){
            if(s->val!=f->val)return false;
            s=s->next;
            f=f->next;
        }
        return true;
    }
};