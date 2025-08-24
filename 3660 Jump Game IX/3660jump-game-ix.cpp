class Solution {
private:
    int binSea(vector<int>&nums,int i,int maxe){
        int idx=i;
        int l=i+1;
        int r=nums.size()-1;
        while(l<=r){
            int mid=((r-l)/2)+l;
            if(nums[mid]<maxe){
                idx=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return idx;
    }
public:
    vector<int> maxValue(vector<int>& nums) {
        // int n=nums.size();
        // vector<int>res=nums;
        // for(int i=0;i<n;i++){
        //     int k=i;
        //     int temp=0;
        //     while(k<n){
        //         temp=max(temp,res[k]);
        //         if(res[i]>res[k])res[i]=temp;
        //         k++;
        //     }
        //     k=i;
        //     int temp1=0;
        //     while(k>=0){
        //         temp1=max(temp1,res[k]);
        //         if(res[i]<res[k]&&temp1>res[i])res[i]=temp1;
        //         k--;
        //     }
        // }
        // return res;
        int n=nums.size();
        int temp=0;
        vector<int>res(n);
        for(int i=0;i<n;i++){
            temp=max(temp,nums[i]);
            res[i]=temp;
        }
        temp=INT_MAX;
        for(int i=n-1;i>=0;i--){
            temp=min(temp,nums[i]);
            nums[i]=temp;
        }
        for(int i=n-1;i>=0;i--){
            int idx=binSea(nums,i,res[i]);
            res[i]=max(res[i],res[idx]);
        }
        return res;
    }
};