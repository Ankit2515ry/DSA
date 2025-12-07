class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<vector<int>>temp(nums.size(),vector<int>(2,0));
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            string s="";
            while(a){
                s+=(a&1)+'0';
                a>>=1;
            }
            int b=0;
            int c=s.size()-1;
            for(int j=0;j<s.size();j++){
                b+=(s[j]-'0')<<c;
                c--;
            }
            temp[i]={b,nums[i]};
        }
        sort(temp.begin(),temp.end());
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            res.push_back(temp[i][1]);
        }
        return res;
    }
};