class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        int n=INT_MIN;
        for(auto it:intervals)n=max(n,it[1]);
        n++;
        vector<int>s(n,0);
        vector<int>e(n,0);
        for(auto &it:intervals){
            s[it[0]]++;
            e[it[1]]--;
        }
        for(int i=1;i<n;i++){
            s[i]+=s[i-1];
            e[i]+=e[i-1];
        }
        int i=0;
        while(i<n&&s[i]==0)i++;
        while(i<n){  
            if(i>0){
                while(i<n&&s[i]==s[i-1]&&e[i]==e[i-1]&&s[i]+e[i]==0)i++;
            }
            int idx=i;
            while(i<n&&s[i]+e[i]!=0)i++;
            res.push_back({idx,i});
            i++;
        }
        return res;
    }
};