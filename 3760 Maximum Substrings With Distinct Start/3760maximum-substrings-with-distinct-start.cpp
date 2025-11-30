class Solution {
public:
    int maxDistinct(string s) {
        int res=0;
        int n=s.size();
        unordered_set<char>st;
        for(auto &it:s){
            if(st.find(it)==st.end()){
                res++;
                st.insert(it);
            }
        }
        return res;
    }
};