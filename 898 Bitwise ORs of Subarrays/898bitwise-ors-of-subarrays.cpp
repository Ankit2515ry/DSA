class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>st;
        unordered_set<int>curr,next;
        for(auto it:arr){
            next={it};
            for(auto x:curr){
                next.insert(it|x);
            }
            curr=next;
            st.insert(curr.begin(),curr.end());
        }
        int res=st.size();
        return res;
    }
};