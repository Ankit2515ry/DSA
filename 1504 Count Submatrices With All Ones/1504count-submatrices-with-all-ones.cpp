class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        //vector<vector<int>>temp=mat;
        for(int i=0;i<mat[0].size();i++){
            int a=0;
            for(int j=0;j<mat.size();j++){
                if(mat[j][i]==1){
                    a+=1;
                    mat[j][i]=a;
                }else{
                    a=0;
                }
            }
        }
        // for(auto it:mat){
        //     for(auto i:it){
        //         cout<<i<<" ";
        //     }cout<<endl;
        // }
        int res=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                int b=INT_MAX;
                for(int k=j;k>=0;k--){
                    b=min(b,mat[i][k]);
                    res+=b;
                }
                //cout<<res<<" ";
            }
            //cout<<endl;
        }
        return res;
    }
};