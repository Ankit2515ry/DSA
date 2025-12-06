class Solution {
public:
    bool check(int n){
        string s;
        if(n==0)return true;
        while(n){
            s.push_back((n&1)+'0');
            n=n>>1;
        }
        string a=s;
        reverse(a.begin(),a.end());
        if(s==a)return true;
        return false;
    }
    int solve(int  n){
        for(int i=0;;i++){
            if(n-i>=0&&check(n-i))return i;
            if(check(n+i))return i;
        }
    }
    vector<int> minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            res[i]=solve(nums[i]);
        }
        return res;
    }
};