class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& w) {
        string res="";
        for(int i=0;i<words.size();i++){
            int sum=0;
            for(auto it:words[i]){
                sum+=w[it-'a'];
            }
            sum%=26;
            sum=25-sum;
            res+=char('a'+sum);
        }
        return res;
    }
};