class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:flights){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        vector<vector<int>> dis(n, vector<int>(k + 2, INT_MAX));
        dis[src][0] = 0;
        priority_queue<pair<int,pair<int ,int>>,vector<pair<int,pair<int ,int>>>,greater<pair<int,pair<int ,int>>>>pq;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            auto [d, pair_us] = pq.top();
            auto [u, s] = pair_us;
            cout<<d<<" "<<u<<" "<<s<<endl;
            pq.pop();
            if(u==dst)return d;
            if(s>k)continue;
            for(auto [v,w]:adj[u]){
                if(dis[v][s+1]>d+w){
                    pair<int,int>p={v,s+1};
                    pair<int,pair<int,int>>pp={d+w,p};
                    pq.push(pp);
                    dis[v][s+1]=d+w;
                }
            }
        }
        return -1;
        //also done using bellman ford algorithm
    }
};