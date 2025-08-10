class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n=value.size();
        long long res=0;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[limit[i]].push_back(value[i]);
        }
        for(auto it:mp){
            vector<int>temp=it.second;
            sort(temp.begin(),temp.end(),greater<>());
            for(int i=0;i<min(it.first,int(temp.size()));i++){
                res+=temp[i];
            }
        }
        return res;
    }
};