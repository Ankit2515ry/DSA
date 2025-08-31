class Solution {
public:
    vector<int> recoverOrder(vector<int>& o, vector<int>& f) {
        vector<int>res;
        unordered_set<int>st;
        for(int i=0;i<f.size();i++){
            st.insert(f[i]);
        }
        for(auto it:o){
            if(st.find(it)!=st.end()){
                st.erase(it);
                res.push_back(it);
            }
        }
        return res;
    }
};