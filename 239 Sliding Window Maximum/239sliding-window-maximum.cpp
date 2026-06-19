class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>>q;
        vector<int>res;
        for(int i=0;i<k;i++){
            while(!q.empty()&&q.back().first<=nums[i])q.pop_back();
            q.push_back({nums[i],i});
        }
        res.push_back(q.front().first);
        for(int i=k;i<nums.size();i++){
            while(!q.empty()&&q.back().first<=nums[i])q.pop_back();
            q.push_back({nums[i],i});
            while(!q.empty()&&q.front().second<(i-k+1))q.pop_front();
            res.push_back(q.front().first);
        }
        return res;

        // deque<int> dq;
        // vector<int> ans;

        // for(int i=0;i<nums.size();i++){

        //     while(!dq.empty() && dq.front() <= i-k)
        //         dq.pop_front();

        //     while(!dq.empty() && nums[dq.back()] <= nums[i])
        //         dq.pop_back();

        //     dq.push_back(i);

        //     if(i >= k-1)
        //         ans.push_back(nums[dq.front()]);
        // }

        // return ans;
    }
};