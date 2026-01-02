class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int>st;
        for(auto &it:nums){
            /*while(!st.empty()&&st.top()<it){
                st.pop();
            }*/
            if(!st.empty()&&it<st.top()) continue;
            st.push(it);
        }
        return st.size();
    }
};