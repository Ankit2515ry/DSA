class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        vector<int>nums2;
        for(auto &it:nums)nums2.push_back(it);
        for(auto &it:nums)nums2.push_back(it);
        int n=nums.size();
        vector<int>res(n,-1);
        for(int i=0;i<2*n;i++){
            while(!st.empty()&&nums2[st.top()]<nums2[i]){
                if(st.top()<n)res[st.top()]=nums2[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};