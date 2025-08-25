class Solution {
public:
    string truncateSentence(string s, int k) {
        string res="";
        int i=0;
        while(k>0&&i<s.size()){
            res+=s[i];
            if(s[i]==' ')k--;
            i++;
        }
        if(res[res.size()-1]==' ')res.pop_back();
        return res;
    }
};