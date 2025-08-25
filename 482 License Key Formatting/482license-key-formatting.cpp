class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string temp="";
        int n=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='-')continue;
            else if(s[i]>='a'&&s[i]<='z')temp+=toupper(s[i]);
            else temp+=s[i];
        }
        string res="";
        int i=temp.size()-1;
        int c=k;
        while(i>=0){
            if(c==0){
                res+='-';
                c=k;
            }
            res+=temp[i];
            i--;
            c--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};