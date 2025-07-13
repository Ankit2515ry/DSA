class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<pair<int,int>>a;
        for(int i=0;i<d.size();i++){
            a.push_back({p[i],d[i]});
        }
        sort(a.begin(),a.end());
        sort(w.begin(),w.end());
        int profit=0;
        int j=w.size()-1;
        int i=d.size()-1;
        while(j>=0&&i>=0){
            if(a[i].second<=w[j]){
                profit+=a[i].first;
                j--;
            }
            else i--;
        }
        return profit;
    }
};