class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums)mp[it]++;
        int n=nums.size();
        int i=0;
        vector<int>res;
        while(i<n){
            int m=0;
            while(mp[m]>0)m++;
            if(m==0){
                res.push_back(0);
                mp[nums[i]]--;
                i++;
                continue;
            }
            unordered_set<int>st;
            int temp=m;
            int j=i;
            while(temp>0){
                int x=nums[j];
                if(x<m&&!st.count(x)){
                    st.insert(x);
                    temp--;
                }
                mp[x]--;
                j++;
            }
            res.push_back(m);
            i=j;
        }
        return res;
    }
};