class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int mod=1e9+7;
        long long res=0;
        vector<pair<int,int>>p;
        //string s="";
        for(int i=0;i<nums1.size();i++){
            if(nums0[i]==0){
                int x=nums1[i];
                while(x--){
                    //s+='1';
                    res*=2;
                    res+=1;
                    res%=mod;
                }
            }else{
                p.push_back({nums1[i],nums0[i]});
            }
        }
        sort(p.begin(),p.end(),[](auto &a,auto &b){
            if(a.first!=b.first)return a.first>b.first;
            return a.second<b.second;
        });
        for(int i=0;i<p.size();i++){
            int a=p[i].first;
            int b=p[i].second;
            while(a--){
                //s+='1';
                res*=2;
                res+=1;
                res%=mod;
            }
            while(b--){
                //s+='0';
                res*=2;
                res%=mod;
            }
        }
        // for(int i=0;i<s.size();i++){
        //     res*=2;
        //     if(s[i]=='1')res+=1;
        //     res%=mod;
        // }
        //cout<<s;
        return res;
    }
};