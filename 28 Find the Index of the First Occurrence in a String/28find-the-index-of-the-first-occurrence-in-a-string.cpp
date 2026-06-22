class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t idx=0;
        if(haystack.find(needle)!=string::npos){
            idx=haystack.find(needle);
            return (int)idx;
        }
        return -1;
    }
};