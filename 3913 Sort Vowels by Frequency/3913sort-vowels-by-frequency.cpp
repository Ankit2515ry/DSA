class Solution {
public:
    string sortVowels(string s) {
        map<char,int>mp;
        map<char,int>mpp;
        int x=1;
        for(auto it:s){
            if(it=='a'|| it=='e' || it=='i' ||it=='o'||it=='u'){
                mp[it]++;
                if(!mpp.count(it)){
                    mpp[it]=x;
                    x++;
                }
            }
        }
        vector<tuple<int ,int,char>>v;
        for(auto it:mp){
            char ch=it.first;
            int f=it.second;
            int oc=mpp[ch];
            v.push_back({f,oc,ch});
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            if (get<0>(a) != get<0>(b)) 
                return get<0>(a) > get<0>(b);  
            return get<1>(a) < get<1>(b);      
        });
        int i=0;
        int n=s.size();
        int j=0;
        // for(auto [f,c,ch]:v){
        //     cout<<ch<<" "<<f<<" "<<c<<endl;
        // }
        while(i<n&&j<v.size()){
            auto [f,c,ch]=v[j];
            while(i<n&&f>0){
                if(s[i]=='a'|| s[i]=='e' || s[i]=='i' ||s[i]=='o'||s[i]=='u'){
                    s[i]=ch;
                    f--;
                }   
                i++;
            }
            i--;
            j++;
            i++;
        }
        return s;
    }
};