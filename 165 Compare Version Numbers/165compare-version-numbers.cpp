class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i=0;
        int j=0;
        int n=v1.size();
        int m=v2.size();
        while(i<n&&j<m){
            string a="";
            string b="";
            while(i<n&&v1[i]=='.')i++;
            while(i<n&&v1[i]!='.'){
                a+=v1[i];
                i++;
            }
            while(j<m&&v2[j]=='.')j++;
            while(j<m&&v2[j]!='.'){
                b+=v2[j];
                j++;
            }
            int x=stoi(a);
            int y=stoi(b);
            if(x>y)return 1;
            if(x<y)return -1;
            i++;
            j++;
        }
        while(i<n){
            string a="";
            while(i<n&&v1[i]=='.')i++;
            while(i<n&&v1[i]!='.'){
                a+=v1[i];
                i++;
            }
            int x=stoi(a);
            if(x!=0)return 1;
            i++;
        }
        while(j<m){
            string b="";
            while(j<m&&v2[j]=='.')j++;
            while(j<m&&v2[j]!='.'){
                b+=v2[j];
                j++;
            }
            int y=stoi(b);
            if(y!=0)return -1;
            j++;
        }
        return 0;
    }
};