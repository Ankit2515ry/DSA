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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //O(n+m) time and space complexity
        // ListNode* dummy=new ListNode(-1);
        // ListNode* temp1=list1;
        // ListNode* temp2=list2;
        // ListNode* temp=dummy;
        // while(temp1&&temp2){
        //     if(temp1->val<temp2->val){
        //         temp->next=new ListNode(temp1->val);
        //         temp=temp->next;
        //         temp1=temp1->next;
        //     }else {
        //         temp->next=new ListNode(temp2->val);
        //         temp=temp->next;
        //         temp2=temp2->next;
        //     }
        // }
        // while(temp1){
        //     temp->next=new ListNode(temp1->val);
        //     temp=temp->next;
        //     temp1=temp1->next;
        // }
        // while(temp2){
        //     temp->next=new ListNode(temp2->val);
        //     temp=temp->next;
        //     temp2=temp2->next;
        // }
        // return dummy->next;


        //O(m+n) time complexity and constant space complexity
        ListNode* res=list1;
        if(list1==nullptr&&list2!=nullptr)res=list2;
        if(list1&&list2&&list1->val>list2->val)res=list2;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* temp=res;
        if(res==temp1&&res){
            temp1=temp1->next;
        }
        if(res==temp2&&res){
            temp2=temp2->next;
        }
        while(temp1&&temp2){
            if(temp1->val<temp2->val){
                temp->next=temp1;
                temp=temp->next;
                temp1=temp1->next;
            }else {
                temp->next=temp2;
                temp=temp->next;
                temp2=temp2->next;
            }
        }
        while(temp1){
            temp->next=temp1;
            temp=temp->next;
            temp1=temp1->next;
        }
        while(temp2){
            temp->next=temp2;
            temp=temp->next;
            temp2=temp2->next;
        }
        return res;
    }
};