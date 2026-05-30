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
    ListNode* rotateRight(ListNode* head, int k) {
        //O(n) time complexity
        if (!head || !head->next || k == 0)
            return head;
        ListNode* temp=head;
        int c=0;
        while(temp){
            c++;
            temp=temp->next;
        }
        int x=c-(k%c);
        if(x==c)return head;
        temp=head;
        x--;
        while(x--){
            temp=temp->next;
        }
        ListNode* res=temp;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=head;
        temp=res->next;
        res->next=nullptr;
        return temp;
    }
};