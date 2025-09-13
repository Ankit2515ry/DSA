class Solution {
public:
    int minArrivalsToDiscard(vector<int>& a, int w, int m) {
        int n=a.size();
        int res=0;
        unordered_map<int,deque<int>>mp;
        for(int i=0;i<n;i++){
            int t=a[i];
            int d=i+1;
            int k=d-w+1;
            while(!mp[t].empty()&&mp[t].front()<k){
                mp[t].pop_front();
            }
            int idx=mp[t].size();
            if(idx<m){
                mp[t].push_back(d);
            }else res++;
        }
        return res;
    }
};