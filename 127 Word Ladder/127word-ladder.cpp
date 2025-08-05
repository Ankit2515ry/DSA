class Solution {
public:
    int ladderLength(string b, string e, vector<string>& word) {
        unordered_set<string>st;
        for(auto it:word)st.insert(it);
        queue<pair<string,int>>q;
        q.push({b,1});
        if(st.find(b)!=st.end())st.erase(b);
        while(!q.empty()){
            string s=q.front().first;
            int step=q.front().second;
            cout<<s<<" "<<step<<endl;
            q.pop();
            for(int i=0;i<s.size();i++){
                string temp=s;
                for(int j=0;j<26;j++){
                    temp[i]='a'+j;
                    if(st.find(temp)!=st.end()){
                        if(temp==e)return step+1;
                        q.push({temp,step+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};