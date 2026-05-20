class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int res=0;
        int n=s.size()+1;
        //cout<<s<<endl;
        while(n--){
            bool f=false;
            for(int i=1;i<s.size();i++){
                if(s[i]=='1'&&s[i-1]=='0'){
                    f=true;
                    s[i-1]='1';
                    s[i]='0';
                    i++;
                }
            }
            if(f)res++;
            else break;
            //cout<<s<<endl;
        } 
        return res;
    }
};