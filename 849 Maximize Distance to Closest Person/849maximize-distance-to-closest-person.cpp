class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int res=0;
        int l=0;
        int r=0;
        if(seats[0]==0){
            int i=0;
            while(i<n&&seats[i]==0){
                l++;
                i++;
            }
        }
        if(seats[n-1]==0){
            int i=n-1;
            while(i>=0&&seats[i]==0){
                r++;
                i--;
            }
        }
        int i=0;
        int j=n;
        if(l)i=l;
        if(r)j=n-r;
        int c=0;
        for(i;i<j;i++){
            if(seats[i]==0)c++;
            else{
                res=max(res,c);
                c=0;
            }
        }
        res=(res+1)/2;
        res=max(res,max(l,r));
        return res;
    }
};