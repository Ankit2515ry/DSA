class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>a=nums;
        int m=n;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j++){
                a[j]=(a[j]+a[j+1])%10;
                //cout<<a[j]<<" ";
            }
            m--;
            //cout<<endl;
        }
        return a[0];
    }
};