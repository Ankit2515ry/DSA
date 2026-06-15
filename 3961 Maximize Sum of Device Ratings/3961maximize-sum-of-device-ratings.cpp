class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n=units.size();
        int m=units[0].size();
        for(auto &it:units){
            sort(it.begin(),it.end());
        }
        long long sum=0;
        if(m==1){
            for(auto it:units)sum+=it[0];
            return sum;
        }
        long long secsum=0;
        long long firmin=1e10;
        for(auto it:units){
            secsum+=it[1];
            firmin=min(firmin,(long long)it[0]);
        }
        for(auto it:units){
            sum=max(sum,secsum+firmin-it[1]);
        }
        return sum;
    }
};