class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& c, vector<string>& q) {
        int m=q.size();
        vector<int>res(m,0);
        unordered_map<string,int>mp;
        string s="";
        for(auto it:c){
            s+=it;
        }
        int n=s.size();
        int i=0;
        while(i<n){
            if(!(s[i]>='a'&&s[i]<='z')){
                i++;
                continue;
            }
            string w="";
            while(i<n){
                if(s[i]>='a'&&s[i]<='z'){
                    w+=s[i];
                    i++;
                }
                else if(s[i]=='-'&&(!w.empty())&&(i+1<n&&s[i+1]>='a'&&s[i+1]<='z')){
                    w+=s[i];
                    i++;
                }
                else break;
            }
            mp[w]++;
        }
        for(int i=0;i<m;i++){
            int qa=mp[q[i]];
            res[i]=qa;
        }
        return res;
    }
};