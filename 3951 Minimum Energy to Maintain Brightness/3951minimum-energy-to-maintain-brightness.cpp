class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long res=0;
        long long b=(brightness+2)/3;
        sort(intervals.begin(),intervals.end());
        int l=intervals[0][0];
        int r=intervals[0][1];
        int size=intervals.size();
        for(int i=1;i<size;i++){
            int nl=intervals[i][0];
            int nr=intervals[i][1];
            if(nl<=r+1){
                r=max(r,nr);
            }else{
                res+=r-l+1;
                l=nl;
                r=nr;
            }
        }
        res+=r-l+1;
        res*=b;
        return res;
    }
};