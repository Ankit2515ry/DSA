class Solution {
public:
    bool scoreBalance(string s) {
        int msum=0;
        for(auto &it:s)msum+=((it-'a')+1);
        if(msum%2==0)msum/=2;
        else return false;
        int sum=0;
        //cout<<msum<<endl;
        for(auto &it:s){
            sum+=((it-'a')+1);
            //cout<<sum<<" ";
            if(msum==sum)return true;
        }
        return false;
    }
};