class Solution {
public:
    string sortVowels(string s) {
        string a="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                a+=s[i];
                s[i]='*';
            }
        }
        sort(a.begin(),a.end());
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                s[i]=a[j];
                j++;
            }
        }
        return s;
    }
};