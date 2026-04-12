class Solution {
public:
    vector<double> internalAngles(vector<int>& s) {
        sort(s.begin(),s.end());
        double a=s[0];
        double b=s[1];
        double c=s[2];
        vector<double>res;
        if(c>=a+b)return res;
        double A = acos((b*b + c*c - a*a) / (2*b*c));
        double B = acos((a*a + c*c - b*b) / (2*a*c));
        double C = acos((a*a + b*b - c*c) / (2*a*b));

        double A_deg = A * 180 / M_PI;
        double B_deg = B * 180 / M_PI;
        double C_deg = C * 180 / M_PI;
        res.push_back(A_deg);
        res.push_back(B_deg);
        res.push_back(C_deg);
        sort(res.begin(),res.end());
        return res;
    }
};