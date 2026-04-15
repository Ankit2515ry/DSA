class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        vector<int>pre1(n);
        vector<int>pre0(n);
        int temp=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')temp++;
            pre1[i]=temp;
        }
        temp=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')temp++;
            pre0[i]=temp;
        }
        int j=0;
        int res=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        temp=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')temp++;
            if(s[i]=='0')temp--;
            if(mp.count(temp)){
                if(i-mp[temp]>1){
                    res=max(res,i-mp[temp]);
                    //cout<<i<<" "<<'n'<<endl;
                }
            }
            if(mp.count(temp-2)){
                if((mp[temp-2]>0&&pre0[mp[temp-2]-1]>0)||(i<n-1&&(pre0[n-1]>pre0[i]))){
                    if(i-mp[temp-2]>1){
                        res=max(res,i-mp[temp-2]);
                        //cout<<i<<" "<<'-'<<endl;
                    }
                }
            }
            if(mp.count(temp+2)){
                if((mp[temp+2]>0&&pre1[mp[temp+2]-1]>0)||(i<n-1&&(pre1[n-1]>pre1[i]))){
                    if(i-mp[temp+2]>1){
                        res=max(res,i-mp[temp+2]);
                        //cout<<i<<" "<<'+'<<endl;
                    }
                }
            }
            if(!mp.count(temp))mp[temp]=i;
        }
        vector<int>pos1(n);
        vector<int>pos0(n);
        temp=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1')temp++;
            pre1[i]=temp;
        }
        temp=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0')temp++;
            pre0[i]=temp;
        }
        unordered_map<int,int>mpp;
        mpp[0]=n;
        temp=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1')temp++;
            if(s[i]=='0')temp--;
            if(mpp.count(temp)){
                if(mpp[temp]-i>1){
                    res=max(res,mpp[temp]-i);
                    //cout<<i<<" "<<'n'<<" "<<"rev"<<endl;
                }
            }
            if(mpp.count(temp-2)){
                if((mpp[temp-2]<n-1&&pre0[mpp[temp-2]+1]>0)||(i>=0&&(pre0[0]>pre0[i]))){
                    if(mpp[temp-2]-1>1){
                        res=max(res,mpp[temp-2]-i);
                        //cout<<i<<" "<<'-'<<" "<<"rev"<<endl;
                    }
                }
            }
            if(mpp.count(temp+2)){
                if((mpp[temp+2]<n-1&&pre1[mpp[temp+2]+1]>0)||(i>=0&&(pre1[0]>pre1[i]))){
                    if(mpp[temp+2]-i>1){
                        res=max(res,mpp[temp+2]-i);
                        //cout<<i<<" "<<'+'<<" "<<"rev"<<endl;
                    }
                }
            }
            if(!mpp.count(temp))mpp[temp]=i;
        }
        return res;
    }
};