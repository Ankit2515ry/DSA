class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& b, vector<vector<int>>& t) {
        unordered_set<long long>st;
        int n=b.size();
        for(int i=0;i<n;i++){
            long long x=0;
            long long y=0;
            long long area=0;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                x=min(t[i][0],t[j][0])-max(b[i][0],b[j][0]);
                y=min(t[i][1],t[j][1])-max(b[i][1],b[j][1]);
                if(x>0&&y>0){
                    long long s=min(x,y);
                    area=s*s;
                }
                st.insert(area);
            }
        }
        long long res=0;
        for(auto it:st){
            res=max(res,it);
        }
        return res;
    }
};