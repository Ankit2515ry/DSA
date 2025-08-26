class Solution {
public:
    // void solve(vector<int>&arr,int i,int j,int m){
    //     if(i==j){
    //         res+=arr[i]-m;
    //         return;
    //     }
    //     int mini=arr[i];
    //     int idx=i;
    //     for(int k=i+1;k<=j;k++){
    //         if(arr[k]<mini){
    //             mini=arr[k];
    //             idx=k;
    //         }
    //     }
    //     res+=mini-m;
    //     m=mini;
    //     if(i<=idx-1)solve(arr,i,idx-1,m);
    //     if(idx+1<=j)solve(arr,idx+1,j,m);
    // }
    // int res=0;
    int minNumberOperations(vector<int>& t) {
        // int e=t.size()-1;
        // solve(t,0,e,0);
        // return res;
        int res=0;
        res+=t[0];
        int n=t.size();
        for(int i=1;i<n;i++){
            if(t[i]>t[i-1])res+=t[i]-t[i-1];
        }
        return res;
    }
};