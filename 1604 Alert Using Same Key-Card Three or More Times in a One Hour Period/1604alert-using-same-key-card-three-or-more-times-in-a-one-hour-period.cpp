class Solution {
public:
    vector<string> alertNames(vector<string>& k, vector<string>& t) {
        unordered_map<string,vector<int>>mp;
        int n=k.size();
        for(int i=0;i<n;i++){
            int a=(stoi(t[i].substr(0,2))*60)+(stoi(t[i].substr(3,2)));
            mp[k[i]].push_back(a);
        }
        vector<string>res;
        vector<int>temp;
        for(auto it:mp){
            temp=it.second;
            sort(temp.begin(),temp.end());
            // for (int i = 2; i < temp.size(); i++) {
            //     if (temp[i] - temp[i-2] <= 60) {
            //         res.push_back(it.first);
            //         break; 
            //     }
            // }
            int j = 0;
            for (int i = 0; i < temp.size(); i++) {
                while (temp[i] - temp[j] > 60) j++;
                if (i - j + 1 >= 3) {
                    res.push_back(it.first);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};