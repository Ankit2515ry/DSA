class Solution {
public:
    int countMonobit(int n) {
        int res=0;
        vector<int>temp={0,1,3,7,15,31,63,127,255,511};
        for(auto &it:temp){
            if(it<=n)res++;
            else break;
        }
        return res;
    }
};