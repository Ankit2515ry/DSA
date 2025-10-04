class Solution {
public:
    int maxArea(vector<int>& h) {
        // int res=0;
        // for(int i=0;i<h.size();i++){
        //     for(int j=0;j<h.size();j++){
        //         res=max(res,abs(i-j)*min(h[i],h[j]));
        //     }
        // }
        // return res;
        int res=0;
        int i=0;
        int j=h.size()-1;
        while(i<j){
            res=max(res,abs(i-j)*min(h[i],h[j]));
            if(h[i]<h[j])i++;
            else j--;
        }
        return res;
    }
};