class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& rq) {
        // vector<long long>res;
        // int n=nums.size();
        // int m=rq.size();
        // for(int i=0;i<m;i++){
        //     nums[rq[i]]=0;
        //     long long qres=0;
        //     long long temp=0;
        //     for(int j=0;j<n;j++){
        //         if(nums[j]==0){
        //             qres=max(qres,temp);
        //             temp=0;
        //         }else temp+=nums[j];
        //     }
        //     qres=max(qres,temp);
        //     res.push_back(qres);
        // }
        // return res;
        //tle


        
        int n=nums.size();
        int m=rq.size();
        vector<long long>res(m,0);
        vector<long long>pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=nums[i]+pre[i-1];
        }
        multiset<long long>st;
        st.insert(pre[n-1]);
        map<int,int>mp;
        mp[0]=n-1;
        auto rcal=[&](int l,int r){
            if(l>r)return 0LL;
            return pre[r]-(l?pre[l-1]:0LL);
        };
        for(int i=0;i<m;i++){
            int k=rq[i];
            auto it=prev(mp.upper_bound(k));
            int l=it->first;
            int r=it->second;
            long long val=rcal(l,r);
            st.erase(st.find(val));
            mp.erase(it);
            if(l<=k-1){
                mp[l]=k-1;
                val=rcal(l,k-1);
                st.insert(val);
            }
            if(k+1<=r){
                mp[k+1]=r;
                val=rcal(k+1,r);
                st.insert(val);
            }
            res[i] = st.empty() ? 0 : *st.rbegin();
        }
        return res;
    }
};
