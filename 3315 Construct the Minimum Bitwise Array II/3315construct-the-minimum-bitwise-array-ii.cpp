class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(auto &it:nums){
        int res=-1;
        int a=1;
        while((it&a)!=0){
            res=it-a;
            a=a<<1;
        }
        it=res;
        }
        return nums;
    }
};