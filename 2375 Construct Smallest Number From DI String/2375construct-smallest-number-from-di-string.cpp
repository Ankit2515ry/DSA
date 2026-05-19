class Solution {
public:
    // int n=0;
    // string solve(string &pattern,string res,vector<bool>&vis){
    //     if(res.size()==n+1)return res;
    //     string ans="999999999";
    //     for(int i=1;i<=9;i++){
    //         if(vis[i])continue;
    //         if(res.size()==0){
    //             vis[i]=1;
    //             ans=min(ans,solve(pattern,res+(char)('0'+i),vis));
    //             vis[i]=0;
    //         }else {
    //             char prev=res.back();
    //             char pres=(char)('0'+i);
    //             char ch=pattern[res.size()-1];
    //             if((ch=='I'&&prev<pres)||(ch=='D'&&prev>pres)){
    //                 vis[i]=1;
    //                 ans=min(ans,solve(pattern,res+pres,vis));
    //                 vis[i]=0;
    //             }
    //         }
    //     }
    //     return ans;
    // }
    string smallestNumber(string pattern) {
        // n=pattern.size();
        // vector<bool>vis(10,0);
        // string res=solve(pattern,"",vis);
        // return res;
        string res="";
        stack<int>st;
        for(int i=0;i<=pattern.size();i++){
            st.push(i+1);
            if(i==pattern.size()||pattern[i]=='I'){
                while(!st.empty()){
                    res+=(char)('0'+st.top());
                    st.pop();
                }
            }
        }
        return res;
    }
};