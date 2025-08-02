class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ml=INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            ml=min(ml,landStartTime[i]+landDuration[i]);
        }
        int mw=INT_MAX;
        for(int i=0;i<waterStartTime.size();i++){
            mw=min(mw,waterStartTime[i]+waterDuration[i]);
        }
        int res_w=INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            int temp=max(mw+landDuration[i],landStartTime[i]+landDuration[i]);
            res_w=min(res_w,temp);
        }
        int res_l=INT_MAX;
        for(int i=0;i<waterStartTime.size();i++){
            int temp=max(ml+waterDuration[i],waterStartTime[i]+waterDuration[i]);
            res_l=min(res_l,temp);
        }
        return min(res_l,res_w);
    }
};