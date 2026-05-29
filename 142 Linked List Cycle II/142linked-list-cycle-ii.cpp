/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //O(n) time complexity
        ListNode* s=head;
        ListNode* f=head;
        while(f&&f->next){
            s=s->next;
            f=f->next->next;
            if(s==f)break;
        }
        if(f==nullptr||f->next==nullptr)return nullptr;
        s=head;
        while(s!=f){
            s=s->next;
            f=f->next;
        }
        return s;
    }
};