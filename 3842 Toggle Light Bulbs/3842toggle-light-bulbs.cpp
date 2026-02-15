class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>temp(100,0);
        for(auto &it:bulbs){
            if(temp[it-1]==0)temp[it-1]=1;
            else temp[it-1]=0;
        }
        vector<int>res;
        for(int i=0;i<100;i++){
            cout<<temp[i]<<" ";
            if(temp[i]==1)res.push_back(i+1);
        }
        return res;
    }
};