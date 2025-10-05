class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int res=0;
        bool f=true;
        for(auto &it:nums)if(it!=0)f=false;
        if(f)return res;
        vector<int>idx(32,0);
        for(auto &it:nums){
            int a=it;
            for(int i=0;i<32;i++){
                //a=a>>i;
                if(a>>i&1==1)idx[i]++;
            }
        }
        for(auto &it:idx){
            cout<<it<<" ";
            if(it%2!=0)return nums.size();
        }
        return nums.size()-1;
    }
};