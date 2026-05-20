class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>temp(n+1,0);
        for(auto it:shifts){
            int i=it[0];
            int j=it[1];
            int d=it[2];
            if(d==1){
                temp[i]++;
                temp[j+1]--;
            }else{
                temp[i]--;
                temp[j+1]++;
            }
        }
        int p=n*26;
        for(int i=1;i<n;i++){
            temp[i]+=temp[i-1];
        }
        for(int i=0;i<n;i++){
            int x=s[i]-'a';
            temp[i]+=x;
            if(temp[i]<0)temp[i]+=p;
            temp[i]%=26;
            //if(temp[i]>25||temp[i]<0)cout<<temp[i]<<" ";
        }
        string res="";
        for(int i=0;i<n;i++){
            char ch='a'+temp[i];
            res+=ch;
        }
        return res;
    }
};