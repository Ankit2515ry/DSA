class Solution {
public:
    int findMinDifference(vector<string>& t) {
        //tle
        // int m=24*60;
        // int res=INT_MAX;
        // int n=t.size();
        // for(int i=0;i<n;i++){
        //     int a=((stoi(t[i].substr(0,2))*60)+(stoi(t[i].substr(3,2))));
        //     for(int j=i+1;j<n;j++){
        //         int b=((stoi(t[j].substr(0,2))*60)+(stoi(t[j].substr(3,2))));
        //         int temp=abs(a-b);
        //         temp=min(temp,abs(m-temp));
        //         res=min(res,temp);
        //     }
        // }
        // return res;
        //O(n)
        // int maxm=24*60;
        // int n=t.size();
        // vector<int>m;
        // int a=0;
        // for(int i=0;i<n;i++){
        //     a=((stoi(t[i].substr(0,2))*60)+(stoi(t[i].substr(3,2))));
        //     m.push_back(a);
        // }
        // sort(m.begin(),m.end());
        // int res=INT_MAX;
        // for(int i=1;i<n;i++){
        //     res=min(res,m[i]-m[i-1]);
        // }
        // res=min(res,maxm-(m[n-1]-m[0]));
        // return res;
        //max O(10*1440);
        int maxm=24*60;
        int n=t.size();
        if(n>maxm)return 0;
        set<int>m;
        int a=0;
        for(int i=0;i<n;i++){
            a=((stoi(t[i].substr(0,2))*60)+(stoi(t[i].substr(3,2))));
            if(m.find(a)!=m.end())return 0;
            m.insert(a);
        }
        int res=INT_MAX;
        int s=*m.begin();
        int p=0;
        for(auto it:m){
            if(it==*m.begin()){
                p=it;
            }
            else{
                res=min(res,it-p);
                p=it;
            }
        }
        // for(auto it : m)cout<<it<<" ";
        res=min(res,maxm-(p-s));
        return res;
    }
};