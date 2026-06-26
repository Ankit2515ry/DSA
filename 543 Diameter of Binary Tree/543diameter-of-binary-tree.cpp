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
        if(node==nullptr)return 0;
        int a=1+solve(node->left);
        int b=1+solve(node->right);
        res=max(res,a+b-2);
        return max(a,b);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return res;
    }
};