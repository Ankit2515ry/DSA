class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int res=0;
        vector<int>a(26,0);
        for(auto &it:s){
            a[it-'a']++;
        }
        int st=-1;
        int idx=-1;
        for(int i=25;i>0;i--){
            if(a[i]!=0&&idx==-1){
                idx=i;
                st=i;
            }
            if(a[i]!=0&&idx!=-1){
                res+=idx-i;
                idx=i;
            }
        }
        if(res!=0)res+=26-st;
        else if(res==0&&idx!=-1){
            res=26-idx;
        }
        return res;
    }
};