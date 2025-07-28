class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool>vis(n+1,true);
        vis[0]=vis[1]=false;
        unordered_set<int>prime;
        vector<int>primev;
        for(long long i=2;i<=n;i++){
            if(vis[i]==true){
                for(long long j=i*i;j<=n;j+=i){
                    vis[j]=false;
                }
            }
        }
        for(int i=0;i<=n;i++){
            if(vis[i]==true){
                prime.insert(i);
                primev.push_back(i);
            }
        }
        vector<vector<int>>ans;
        for(auto it:primev){
            if(prime.find(n-it)!=prime.end()){
                ans.push_back({it,n-it});
                prime.erase(it);
            }
        }
        return ans;
    }
};