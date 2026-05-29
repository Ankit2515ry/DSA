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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //O(m*n) time complexity
        // ListNode* temp=headA;
        // while(temp){
        //     ListNode* it=headB;
        //     while(it){
        //         if(temp==it)return temp;
        //         it=it->next;
        //     }
        //     temp=temp->next;
        // }
        // return nullptr;

        //O(m+n) time and space complexity
        // unordered_set<ListNode*>st;
        // ListNode* temp=headA;
        // while(temp){
        //     st.insert(temp);
        //     temp=temp->next;
        // }
        // temp=headB;
        // while(temp){
        //     if(st.count(temp))return temp;
        //     temp=temp->next;
        // }
        // return nullptr;

        //O(m+n) time complexity and constant space
        // int n=0;
        // int m=0;
        // ListNode* a=headA;
        // while(a){
        //     n++;
        //     a=a->next;
        // }
        // a=headB;
        // while(a){
        //     m++;
        //     a=a->next;
        // }
        // int x=abs(n-m);
        // a=headA;
        // ListNode* b=headB;
        // if(m>n){
        //     while(x--){
        //         b=b->next;
        //     }
        // }else {
        //     while(x--){
        //         a=a->next;
        //     }
        // }
        // while(a!=b){
        //     a=a->next;
        //     b=b->next;
        // }
        // return a;

        ListNode* a=headA;
        ListNode* b=headB;
        while(a!=b) {
            a=(a==nullptr)?headB:a->next;
            b=(b==nullptr)?headA:b->next;
        }
        return a;
    }
};