class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        for(int i=0;i<n-1;i++){
            int xmi=points[i][0];
            int ymi=INT_MIN;
            int yma=points[i][1];
            for(int j=i+1;j<n;j++){
                if(points[j][0]>=xmi&&points[j][1]>ymi&&points[j][1]<=yma){
                    res++;
                    xmi=points[j][0];
                    ymi=points[j][1];
                }
            }
        }
        return res;
    }
};