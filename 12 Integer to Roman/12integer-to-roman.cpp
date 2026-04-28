class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,char>mp={
            {1,'I'},{5,'V'},{10,'X'},{50,'L'},{100,'C'},{500,'D'},{1000,'M'}
        };
        int pdiv=1000;
        int div=1000;
        string res="";
        while(num){
            int d=num/div;
            if(d<4){
                for(int i=0;i<d;i++){
                    res+=mp[div];
                }
            }else if(d==4){
                res+=mp[div];
                res+=mp[pdiv/2];
            }else if(d>4&&d<9){
                res+=mp[pdiv/2];
                for(int i=0;i<d-5;i++){
                    res+=mp[div];
                }
            }else{
                res+=mp[div];
                res+=mp[pdiv];
            }
            num%=div;
            pdiv=div;
            div/=10;
        }
        return res;
    }
};