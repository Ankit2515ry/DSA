class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char>st;
        for(auto it:s){
            if(st.count(it))return it;
            st.insert(it);
        }
        return '0';
    }
};