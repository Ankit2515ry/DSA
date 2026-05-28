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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //O(n) time complexity
        // int n=0;
        // int m=0;
        // ListNode* temp=l1;
        // while(temp){
        //     temp=temp->next;
        //     n++;
        // }
        // temp=l2;
        // while(temp){
        //     temp=temp->next;
        //     m++;
        // }
        // ListNode* res=l1;
        // if(n>m){
        //     int c=0;
        //     temp=res;
        //     ListNode* prev=temp;
        //     ListNode* b=l2;
        //     while(b){
        //         if(temp->next==nullptr)prev=temp;
        //         temp->val+=c+b->val;
        //         c=temp->val/10;
        //         temp->val%=10;
        //         temp=temp->next;
        //         b=b->next;
        //     }
        //     while(temp){
        //         if(temp->next==nullptr)prev=temp;
        //         temp->val+=c;
        //         c=temp->val/10;
        //         temp->val%=10;
        //         temp=temp->next;
        //     }
        //     if(c)prev->next = new ListNode(1);
        // }else{
        //     ListNode* prev=temp;
        //     res=l2;
        //     int c=0;
        //     temp=res;
        //     ListNode* a=l1;
        //     while(a){
        //         if(temp->next==nullptr)prev=temp;
        //         temp->val+=c+a->val;
        //         c=temp->val/10;
        //         temp->val%=10;
        //         temp=temp->next;
        //         a=a->next;
        //     }
        //     while(temp){
        //         if(temp->next==nullptr)prev=temp;
        //         temp->val+=c;
        //         c=temp->val/10;
        //         temp->val%=10;
        //         temp=temp->next;
        //     }
        //     if(c)prev->next = new ListNode(1);
        // }
        // return res;

        //O(n) time and space complexity
        ListNode dummy(-1);
        ListNode* temp=&dummy;
        ListNode* a=l1;
        ListNode* b=l2;
        int c=0;
        while(a||b||c){
            int v=0;
            if(a){
                v+=a->val;
                a=a->next;
            }
            if(b){
                v+=b->val;
                b=b->next;
            }
            if(c)v++;
            c=v/10;
            v%=10;
            temp->next = new ListNode(v);
            temp=temp->next;
        }
        return dummy.next;
    }
};