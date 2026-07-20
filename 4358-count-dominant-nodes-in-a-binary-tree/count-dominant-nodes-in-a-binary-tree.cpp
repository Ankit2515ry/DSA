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
    int res=0;
    int solve(TreeNode* node){
        if(node==nullptr)return INT_MIN;
        int a=solve(node->left);
        int b=solve(node->right);
        int m=max({node->val,a,b});
        if(node->val==m)res++;
        return m;
    }
    int countDominantNodes(TreeNode* root) {
        solve(root);
        return res;
    }
};