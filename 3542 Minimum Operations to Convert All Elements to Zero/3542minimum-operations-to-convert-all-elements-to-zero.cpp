class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&st.top()>=nums[i]){
                if(st.top()>nums[i]){
                    res++;
                }
                st.pop();
            }
            if(nums[i]!=0) st.push(nums[i]);
        }
        while(!st.empty()){
            res++;
            st.pop();
        }
        return res;
    }
};