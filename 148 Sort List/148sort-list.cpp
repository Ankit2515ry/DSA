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
    ListNode* sortList(ListNode* head) {
        vector<int>a;
        ListNode* temp = head;
        while(temp){
            a.push_back(temp->val);
            temp=temp->next;
        }
        sort(a.begin(),a.end());
        ListNode* dummy=new ListNode(0);
        temp=dummy;
        for(int i=0;i<a.size();i++){
            temp->next=new ListNode(a[i]);
            temp=temp->next;
        }
        return dummy->next;
    }
};