class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int max_players=0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int j=trainers.size()-1;
        for(int i=players.size()-1;i>=0&&j>=0;i--){
            if(players[i]<=trainers[j]){
                max_players++;
                j--;
            }
        }
        return max_players;
    }
};