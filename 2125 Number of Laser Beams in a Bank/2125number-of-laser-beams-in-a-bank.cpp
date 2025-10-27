class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res=0;
        int n=bank.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            int a=0;
            for(auto &it:bank[i]){
                if(it=='1')a++;
            }
            if(a!=0)temp.push_back(a);
        }
        int m=temp.size();
        for(int i=0;i<m-1;i++){
            res+=temp[i]*temp[i+1];
        }
        return res;
    }
};