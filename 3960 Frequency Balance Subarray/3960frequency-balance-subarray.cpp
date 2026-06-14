class Solution {
public:
    int getLength(vector<int>& nums) {
        // int n=nums.size();
        // vector<vector<int>>sub;
        // for(int i=0;i<n;i++){
        //     vector<int>temp;
        //     for(int j=i;j<n;j++){
        //         temp.push_back(nums[j]);
        //         sub.push_back(temp);
        //     }
        // }
        // int res=1;
        // n=sub.size();
        // for(int i=0;i<n;i++){
        //     if(sub[i].size()==1)continue;
        //     unordered_map<int,int>mp;
        //     for(auto it:sub[i]){
        //         mp[it]++;
        //     }
        //     unordered_set<int>st;
        //     for(auto [k,v]:mp)st.insert(v);
        //     if(mp.size()==1)res=max(res,(int)sub[i].size());
        //     if(st.size()!=2)continue;
        //     auto it=st.begin();
        //     int a=*it;
        //     it++;
        //     int b=*it;
        //     if(max(a,b)==2*min(a,b))res=max(res,(int)sub[i].size());
        // }
        // return res;

        int n=nums.size();
        int res=1;
        for(int i=0;i<n;i++){
            unordered_map<int,int>f;
            unordered_map<int,int>c;
            for(int j=i;j<n;j++){
                int v=nums[j];
                if(f.count(v)){
                    int olf=f[v];
                    c[olf]--;
                    if(c[olf]==0){
                        c.erase(olf);
                    }
                }
                f[v]++;
                int nef=f[v];
                c[nef]++;
                int subs=j-i+1;
                if(f.size()==1)res=max(res,subs);
                else if(c.size()==2){
                    auto it=c.begin();
                    int a=it->first;
                    int b=next(it)->first;
                    if(max(a,b)==2*min(a,b))res=max(res,subs);
                }
            }
        }
        return res;
    }
};