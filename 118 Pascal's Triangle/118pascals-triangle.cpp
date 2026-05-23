class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // vector<vector<int>>res;
        // res.push_back({1});
        // if(numRows==1)return res;
        // res.push_back({1,1});
        // if(numRows==2)return res;
        // int x=numRows-2;
        // while(x--){
        //     vector<int>temp;
        //     temp.push_back(1);
        //     int sz=res.size()-1;
        //     for(int i=0;i<res[sz].size()-1;i++){
        //         temp.push_back(res[sz][i]+res[sz][i+1]);
        //     }
        //     temp.push_back(1);
        //     res.push_back(temp);
        // }
        // return res;
        int i=0;
        vector<vector<int>>res(numRows);
        res[i]={1};
        i++;
        if(numRows==1)return res;
        res[i]={1,1};
        i++;
        if(numRows==2)return res;
        int x=numRows-2;
        while(x--){
            int sz=res[i-1].size()-1;
            res[i].push_back(1);
            for(int j=0;j<sz;j++){
                res[i].push_back(res[i-1][j]+res[i-1][j+1]);
            }
            res[i].push_back(1);
            i++;
        }
        return res;
    }
};