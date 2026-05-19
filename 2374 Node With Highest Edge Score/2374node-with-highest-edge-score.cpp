class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<int,vector<int>>mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i]].push_back(i);
        }
        int res=0;
        long long val=INT_MIN;
        for(auto it:mp){
            int k=it.first;
            auto a=it.second;
            long long v=0;
            for(auto i:a)v+=i;
            if(val<v){
                val=v;
                res=k;
            }else if(val==v){
                res=min(res,k);
            }
        }
        return res;
    }
};