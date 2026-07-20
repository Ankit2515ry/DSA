class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int c0=0;
        int c1=0;
        for(auto it:s){
            if(it=='0')c0++;
            else c1++;
        }
        vector<bool>res(strs.size(),false);
        for(int i=0;i<strs.size();i++){
            int x=0;
            int y=0;
            int z=0;
            for(auto it:strs[i]){
                if(it=='0')x++;
                else if(it=='1')y++;
                else z++;
            }
            int n0=c0-x;
            if(n0<0||n0>z){
                continue;
            }
            int p=n0;
            string temp="";
            for(auto it:strs[i]){
                if(it=='?'){
                    if(p>0){
                        temp+='0';
                        p--;
                    }else{
                        temp+='1';
                    }
                }else{
                    temp+=it;
                }
            }
            bool ans=true;
            int a=0;
            int b=0;
            for(int j=0;j<s.size();j++){
                if(s[j]=='0')a++;
                if(temp[j]=='0')b++;
                if(b<a){
                    ans=false;
                    break;
                }
            }
            res[i]=ans;
        }
        return res;
    }
};