class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>s;
        vector<int>l;
        if(n%2==0){
            int i=0;
            for(;i<n/2;i++)s.push_back(nums[i]);
            for(;i<n;i++)l.push_back(nums[i]);
        }else{
            int i=0;
            for(;i<=n/2;i++)s.push_back(nums[i]);
            for(;i<n;i++)l.push_back(nums[i]);
        }
        reverse(s.begin(), s.end());
        reverse(l.begin(), l.end());
        int k=0;
        for(int i=0;i<n/2;i++){
            nums[k]=s[i];
            k++;
            nums[k]=l[i];
            k++;
        }
        if(n%2!=0){
            nums[n-1]=s[n/2];
        }
    }
};