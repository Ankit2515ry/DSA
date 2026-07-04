/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // unordered_map<int,Node*>mpp;
    // void solve(Node* node,unordered_map<int,Node*>&mp,vector<int>&vis){
    //     if(node==nullptr)return;
    //     int v=node->val;
    //     if(vis[v]!=0)return;
    //     Node* a=new Node(v);
    //     mp[v]=a;
    //     vis[v]=1;
    //     mpp[v]=node;
    //     for(auto it:node->neighbors){
    //         solve(it,mp,vis);
    //     }
    // }
    unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
        // if(node==nullptr) return nullptr;
        // unordered_map<int,Node*>mp;
        // vector<int>vis(101,0);
        // solve(node,mp,vis);
        // for(auto it:mpp){
        //     int v=it.first;
        //     auto n=mp[v];
        //     for(auto i:it.second->neighbors){
        //         int vv=i->val;
        //         n->neighbors.push_back(mp[vv]);
        //     }
        // }
        // return mp[node->val];
        if(node==nullptr)return node;
        if(mp.count(node))return mp[node];
        Node* clone=new Node(node->val);
        mp[node]=clone;
        for(auto it:node->neighbors){
            clone->neighbors.push_back(cloneGraph(it));
        }
        return clone;
    }
};