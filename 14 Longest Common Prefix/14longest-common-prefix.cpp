class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        int m=201;
        for(auto &it:strs)m=min(m,(int)it.size());
        int j=0;
        int n=strs.size();
        while(m--){
            bool f=true;
            for(int i=1;i<n;i++){
                if(strs[i][j]!=strs[i-1][j])f=false;
            }
            if(f)res+=strs[0][j];
            else break;
            j++;
        }
        return res;
    }
};