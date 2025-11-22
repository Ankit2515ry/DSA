class Solution {
public:
    int minimumFlips(int n) {
        string s="";
        int res=0;
        while(n>0){
            s.push_back('0'+(n&1));
            n>>=1;
        }
        reverse(s.begin(),s.end());
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])res++;
            i++;
            j--;
        }
        return res*2;
    }
};