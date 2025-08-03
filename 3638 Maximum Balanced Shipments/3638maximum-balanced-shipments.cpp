class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int res=0;int ma=0;
        for(int i=0;i<weight.size();i++){
            ma=max(ma,weight[i]);
            if(ma>weight[i]){
                res++;
                ma=0;
            }
        }
        return res;
    }
};