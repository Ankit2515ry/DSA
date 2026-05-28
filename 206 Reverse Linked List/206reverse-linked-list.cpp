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
    ListNode* reverseList(ListNode* head) {

        //O(n) time and space complexity using a vector to store value then reverse it then design another LinkList 
        // vector<int>temp;

        // ListNode* s=head;
        // while(s!=nullptr){
        //     temp.push_back(s->val);
        //     s=s->next;
        // }
        // reverse(temp.begin(),temp.end());
        // ListNode* dummy=new ListNode(-1);
        // s=dummy;
        // for(auto it:temp){
        //     s->next=new ListNode(it);
        //     s=s->next;
        // }
        // return dummy->next;

        //O(n) time and space complexity using stack

        // stack<ListNode*>st;
        // ListNode* s=head;
        // st.push(nullptr);
        // while(s!=nullptr){
        //     st.push(s);
        //     s=s->next;
        // }
        // if(st.size()==1)return nullptr;
        // auto res=st.top();
        // while(st.size()>1){
        //     auto prev=st.top();
        //     st.pop();
        //     auto curr=st.top();
        //     prev->next=curr;
        // }
        // return res;

        if(head == nullptr || head->next==nullptr )return head;
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* succ=head->next;
        succ=curr->next;
        prev->next=nullptr;
        while(succ!=nullptr){
            curr->next=prev;
            prev=curr;
            curr=succ;
            succ=succ->next;
        }
        curr->next=prev;
        return curr;
    }
};