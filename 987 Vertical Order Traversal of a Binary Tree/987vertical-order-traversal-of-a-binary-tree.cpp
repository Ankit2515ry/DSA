/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<tuple<int,int,int>>temp;
    void solve(TreeNode* node,int col,int row){
        if(node==nullptr)return;
        temp.push_back({col,row,node->val});
        solve(node->left,col-1,row+1);
        solve(node->right,col+1,row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0,0);
        sort(temp.begin(),temp.end());
        int n=get<0>(temp.front());
        int p=get<0>(temp.back());
        int sz=abs(n)+p+1;
        vector<vector<int>>res(sz);
        for(int i=0;i<temp.size();i++){
            int idx=get<0>(temp[i])+abs(n);
            int v=get<2>(temp[i]);
            res[idx].push_back(v);
        }
        return res;
    }
};