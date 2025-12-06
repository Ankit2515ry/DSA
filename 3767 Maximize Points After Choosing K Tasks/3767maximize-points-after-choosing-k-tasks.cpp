class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        int n=t1.size();
        long long res=0;
        for(auto &it:t2)res+=it;
        vector<int>temp(n);
        for(int i=0;i<n;i++){
            temp[i]=t1[i]-t2[i];
        }
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        for(int i=0;i<k;i++)res+=temp[i];
        for(int i=k;i<n;i++){
            if(temp[i]>0)res+=temp[i];
        }
        return res;
    }
};