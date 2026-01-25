class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int>temp;
        for(int it:nums){
            if(it>-1)temp.push_back(it);
        }
        k=(temp.size()==0)?0:k%temp.size();
        vector<int>r(temp.size());
        for(int i=0;i<temp.size();i++){
            int j=(i-k+temp.size())%(temp.size());
            r[j]=temp[i];
        }
        vector<int>res;
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                res.push_back(nums[i]);
            }else{
                res.push_back(r[j]);
                j++;
            }
        }
        return res;
    }
};