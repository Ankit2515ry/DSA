class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0;
        int two=0;
        for(auto it : nums){
            one=(one^it)&~two;
            //cout<<"one->"<<one<<endl;
            two=(two^it)&~one;
            //cout<<"two->"<<two<<endl;
        }
        return one;
    }
};