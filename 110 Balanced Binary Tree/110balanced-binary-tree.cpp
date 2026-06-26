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
    bool res=true;
    int solve(TreeNode* node){
        if(node==nullptr)return 0;
        int a=1+solve(node->left);
        int b=1+solve(node->right);
        if(a>b+1)res=false;
        if(a+1<b)res=false;
        return max(a,b);
    }
    bool isBalanced(TreeNode* root) {
        solve(root);
        return res;
    }
};