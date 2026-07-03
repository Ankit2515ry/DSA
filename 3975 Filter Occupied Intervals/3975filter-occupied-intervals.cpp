class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        int n=occupiedIntervals.size();
        vector<vector<int>>res;
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        if(n==0)return res;
        int s=occupiedIntervals[0][0];
        int e=occupiedIntervals[0][1];
        for(int i=1;i<n;i++){
            if(occupiedIntervals[i][0]<=e+1){
                e=max(e,occupiedIntervals[i][1]);
            }else{
                if((s<freeStart&&e<freeStart)||(s>freeEnd)){
                    res.push_back({s,e});
                }else{
                    if(s<freeStart&&e<=freeEnd){
                        res.push_back({s,freeStart-1});
                    }else if(s>=freeStart&&s<=freeEnd&&e>freeEnd){
                        res.push_back({freeEnd+1,e});
                    }else if(s<freeStart&&e>freeEnd){
                        res.push_back({s,freeStart-1});
                        res.push_back({freeEnd+1,e});
                    }
                }
                s=occupiedIntervals[i][0];
                e=occupiedIntervals[i][1];
            }
        }
        if((s<freeStart&&e<freeStart)||(s>freeEnd)){
            res.push_back({s,e});
        }else{
            if(s<freeStart&&e<=freeEnd){
                res.push_back({s,freeStart-1});
            }else if(s>=freeStart&&s<=freeEnd&&e>freeEnd){
                res.push_back({freeEnd+1,e});
            }else if(s<freeStart&&e>freeEnd){
                res.push_back({s,freeStart-1});
                res.push_back({freeEnd+1,e});
            }
        }
        return res;
    }
};