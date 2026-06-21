class Solution {
public:
    //code -> tle
        // int c=1;
        // bool f=true;
        // string temp=a;
        // if(a.find(b)!=string::npos)return c;
        // a+=temp;
        // c++;
        // while(a.find(b)==string::npos){
        //     if(a.size()>2*b.size()){
        //         f=false;
        //         break;
        //     }
        //     //cout<<a<<endl;
        //     c++;
        //     a+=temp;
        // }
        // //cout<<a<<endl;
        // if(!f)return -1;
        // return c;
    int repeatedStringMatch(string a, string b) {
        // if(a.size()>b.size()){
        //     if(a.find(b)!=string::npos)return 1;
        //     string temp=a;
        //     temp+=a;
        //     if(temp.find(b)!=string::npos)return 2;
        //     return -1;
        // }
        // string temp="";
        // while(temp.size()<2*b.size())temp+=a;
        // if(temp.find(b)==string::npos)return -1;
        // int res=0;
        // temp="";
        // while(temp.size()<b.size()){
        //     temp+=a;
        //     res++;
        // }
        // while(temp.find(b)==string::npos){
        //     res++;
        //     temp+=a;
        // }
        // return res;
        int res=0;
        string temp="";
        while(temp.size()<b.size()){
            temp+=a;
            res++;
        }
        if(temp.find(b)!=string::npos)return res;
        temp+=a;
        res++;
        if(temp.find(b)!=string::npos)return res;
        return -1;
    }
};