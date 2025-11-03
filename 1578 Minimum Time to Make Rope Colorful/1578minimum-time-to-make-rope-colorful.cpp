class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res=0;
        int n=colors.size();
        for(int i=1;i<n;i++){
            int temp=0;
            while(i<n&&colors[i]==colors[i-1]){
                res+=neededTime[i-1];
                temp=max(temp,neededTime[i-1]);
                i++;
            }
            res+=neededTime[i-1];
            temp=max(temp,neededTime[i-1]);
            res-=temp;
        }
        return res;
    }
};