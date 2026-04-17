class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        vector<long long>temp;
        for(int i=1;i<=1000;i++){
            long long x=1LL*i*i*i;
            temp.push_back(x);
        }
        unordered_map<long long ,int>mp;
        for(int i=0;i<temp.size();i++){
            for(int j=i+1;j<temp.size();j++){
                if(temp[i]+temp[j]<=n)mp[temp[i]+temp[j]]++;
            }
        }
        vector<int>res;
        for(auto it:mp){
            if(it.second>1){
                res.push_back(it.first);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};