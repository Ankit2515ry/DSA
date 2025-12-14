class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long long sum=0;
        for(auto &it:balance)sum+=it;
        if(sum<0)return -1;
        int idx=-1;
        for(int i=0;i<balance.size();i++){
            if(balance[i]<0){
                idx=i;
                break;
            }
        }
        if(idx==-1)return 0;
        long long steps=0;
        int n=balance.size();
        sum=-balance[idx];
        int i=(idx-1+n)%n;
        int j=(idx+1)%n;
        int x=1;
        while(sum>0&&x<n){
            if(balance[i]>0){
                long long temp= min<long long>(balance[i],sum);
                steps+=temp*x;
                sum-=temp;
            }if(sum>0&&balance[j]>0){
               long long temp= min<long long>(balance[j],sum);
                steps+=temp*x;
                sum-=temp;
            }
            i=(i-1+n)%n;
            j=(j+1)%n;
            x++;
        }
        return (sum==0)?steps:-1;
    }
};