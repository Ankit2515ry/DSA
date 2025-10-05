class Solution {
public:
    string removeSubstring(string s, int k) {
        string merostalin = s;
        string res = "";
        string pattern = string(k, '(') + string(k, ')');
        for (char ch : merostalin) {
            res.push_back(ch);
            if (res.size() >= 2 * k) {
                if (res.compare(res.size() - 2 * k, 2 * k, pattern) == 0) {
                    res.resize(res.size() - 2 * k);
                }
            }
        }
        return res;
    }
};
