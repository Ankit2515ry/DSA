class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //O(n2) time complexity and O(26) constant space complexity
        // int res=0;
        // int n=s.size();
        // for(int i=0;i<n;i++){
        //     unordered_set<char>st;
        //     for(int j=i;j<n;j++){
        //         if(st.count(s[j])){
        //             res=max(res,j-i);
        //             break;
        //         }
        //         st.insert(s[j]);
        //     }
        // }
        // return res;

        //O(n) time complexity and constant space
        // int res=0;
        // int n=s.size();
        // unordered_map<char,int>mp;
        // int j=0;
        // for(int i=0;i<n;i++){
        //     if(mp.count(s[i])&&mp[s[i]]>=j){
        //         j=mp[s[i]]+1;
        //     }
        //     mp[s[i]]=i;
        //     res=max(res,i-j+1);
        // }
        // return res;

        //O(n) time complexity and constant time complexity
        int res=0;
        int n=s.size();
        int j=0;
        vector<int>vis(256,-1); // for 256 char
        for(int i=0;i<n;i++){
            j=max(j,vis[s[i]]+1);
            vis[s[i]]=i;
            res=max(res,i-j+1);
        }
        return res;
    }
};