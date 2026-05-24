
#define B_SIZE 200
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n=nums2.size();
        int m=(n+B_SIZE-1)/B_SIZE;
        vector<unordered_map<long long,int>> blockMap(m);
        vector<long long> blockOff(m);
        vector<int> answer;
        for(int i=0;i<n;i++){
            blockMap[i/B_SIZE][nums2[i]]++;
        }

        for(auto &it:queries){
            if(it[0]==1){
                int j=it[1];
                while(j<=it[2]){
                    if (j % B_SIZE == 0 && j + B_SIZE - 1 <= it[2]) {
                        blockOff[j/B_SIZE]+=it[3];
                        j += B_SIZE;
                    }
                    else {
                        blockMap[j/B_SIZE][nums2[j]]--;
                        nums2[j]+=it[3];
                        blockMap[j/B_SIZE][nums2[j]]++;
                        j++;
                    }
                }
            }
            else{
                int ans=0;
                for(auto &num:nums1){
                    for(int j=0;j<m;j++){
                        long long rem=it[1]-num-blockOff[j];
                        if(blockMap[j].find(rem)!=blockMap[j].end()) ans+=blockMap[j][rem];
                    }
                }
                answer.push_back(ans);
            }
            // for(auto &it:nums2) cout<<it<<" ";
            // cout<<endl;
            // for(auto &it:blockOff) cout<<it<<" ";
            // cout<<endl;
        }
        return answer;
    }
};