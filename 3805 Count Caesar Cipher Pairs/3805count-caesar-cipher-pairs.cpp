class Solution {
public:
    long long countPairs(vector<string>& words) {
        long long res=0;
        unordered_map<string,long long>f;
        for(int i=0;i<words.size();i++){
            string s;
            for(int j=1;j<words[i].size();j++){
                int d=(words[i][j]-words[i][j-1]+26)%26;
                s+=(char)('a'+d);
            }
            f[s]++;
        }
        for(auto &[a,b]:f){
            res+=b*(b-1)/2;
        }
        return res;
    }
};