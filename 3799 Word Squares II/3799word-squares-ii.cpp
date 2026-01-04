class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>>res;
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                for(int k=0;k<n;k++){
                    if(i==k||j==k)continue;
                    for(int l=0;l<n;l++){
                        if(i==l||j==l||k==l)continue;
                        string &t=words[i];
                        string &le=words[j];
                        string &r=words[k];
                        string &b=words[l];
                        if(t[0]==le[0]&&t[3]==r[0]&&b[0]==le[3]&&b[3]==r[3]){
                            res.push_back({t,le,r,b});
                        }
                    }
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};