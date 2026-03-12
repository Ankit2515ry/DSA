class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mp;
        int ch=0;
        for(int i=0;i<key.size();i++){
            if(key[i]==' '||mp.count(key[i]))continue;
            else {
                mp[key[i]]=char('a'+ch);
                ch++;
            }
        }
        string s="";
        for(int i=0;i<message.size();i++){
            if(message[i]==' ')s+=' ';
            else {
                s+=mp[message[i]];
            }
        }
        return s;
    }
};