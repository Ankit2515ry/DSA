class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //O(n4log(n)) time and O(n4) space complexity
        // vector<vector<int>>res;
        // int n=nums.size();
        // set<vector<int>>st;
        // for(int a=0;a<n;a++){
        //     for(int b=a+1;b<n;b++){
        //         for(int c=b+1;c<n;c++){
        //             for(int d=c+1;d<n;d++){
        //                 if(nums[a] + nums[b] + nums[c] + nums[d] == target){
        //                     vector<int>temp={nums[a] , nums[b] , nums[c] , nums[d]};
        //                     sort(temp.begin(),temp.end());
        //                     if(!st.count(temp))res.push_back(temp);
        //                     st.insert(temp);
        //                 }
        //             }
        //         }
        //     }
        // }
        // return res;

        //O(n3log(n)) time and O(n3) space complexity
        int n=nums.size();
        set<vector<int>>st;
        for(int a=0;a<n;a++){
            for(int b=a+1;b<n;b++){
                long long tempt=(long long)target-nums[a]-nums[b];
                unordered_set<long long>stt;
                for(int c=b+1;c<n;c++){
                    long long v=tempt-nums[c];
                    if(stt.count(nums[c])){
                        vector<int>temp={nums[a],nums[b],(int)v,nums[c]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    stt.insert(v);
                }
            }
        }
        vector<vector<int>>res;
        for(auto it:st)res.push_back(it);
        return res;
        // //we can do this by sorting the array then 2 nested loop and finding target by two pointer 
        //  int n = nums.size();
        // vector<vector<int>> res;
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i < n; i++) {
        //     if(i > 0 && nums[i] == nums[i-1])
        //         continue;
        //     for(int j = i + 1; j < n; j++) {
        //         if(j > i + 1 && nums[j] == nums[j-1])
        //             continue;
        //         int l = j + 1;
        //         int r = n - 1;
        //         long long need =
        //             (long long)target - nums[i] - nums[j];
        //         while(l < r) {
        //             long long sum = nums[l] + nums[r];
        //             if(sum == need) {
        //                 res.push_back({
        //                     nums[i],
        //                     nums[j],
        //                     nums[l],
        //                     nums[r]
        //                 });
        //                 l++;
        //                 r--;
        //                 while(l < r &&
        //                       nums[l] == nums[l-1])
        //                     l++;
        //                 while(l < r &&
        //                       nums[r] == nums[r+1])
        //                     r--;
        //             }
        //             else if(sum < need)
        //                 l++;
        //             else
        //                 r--;
        //         }
        //     }
        // }
        // return res;
    }
};