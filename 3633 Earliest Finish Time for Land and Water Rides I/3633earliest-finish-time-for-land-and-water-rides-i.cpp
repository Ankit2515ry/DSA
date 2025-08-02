class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int res=INT_MAX;
        int lt=landStartTime.size();
        int wt=waterStartTime.size();
        for(int i=0;i<lt;i++){
            int temp=landStartTime[i]+landDuration[i];
            for(int j=0;j<wt;j++){
                if(waterStartTime[j]+waterDuration[j]<=landStartTime[i]){
                    res=min(res,temp);
                }else if(waterStartTime[j]>=temp){
                    res=min(res,waterStartTime[j]+waterDuration[j]);
                }else{
                    if(waterStartTime[j]<landStartTime [i]){
                        res=min(res,waterStartTime[j]+waterDuration[j]+landDuration[i]);
                    }else {
                        res=min(res,landStartTime [i]+waterDuration[j]+landDuration[i]);
                    }
                }
            }
        }
        return res;
    }
};