class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int>f(10);
        for(auto it:nums){
            int num=it;
            int mini=9;
            int maxi=0;
            while(it){
                int d=it%10;
                mini=min(mini,d);
                maxi=max(maxi,d);
                it/=10;
            }
            int d=maxi-mini;
            f[d]+=num;
        }
        for(int i=9;i>=0;i--){
            if(f[i]!=0)return f[i];
        }
        return 0;
    }
};