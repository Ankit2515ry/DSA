class Solution {
public:
    int solve(int a){
        string s=to_string(a);
        int n=s.size();
        if(n<3)return 0;
        int temp=0;
        for(int i=1;i<n-1;i++){
            if(s[i]>s[i-1]&&s[i]>s[i+1])temp++;
            if(s[i]<s[i-1]&&s[i]<s[i+1])temp++;
        }
        return temp;
    }
    int totalWaviness(int num1, int num2) {
        int res=0;
        for(int i=num1;i<=num2;i++){
            res+=solve(i);
        }return res;
    }
};