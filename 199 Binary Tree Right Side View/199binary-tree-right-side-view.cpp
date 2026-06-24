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
    vector<int> rightSideView(TreeNode* root) {
        // vector<int>res;
        // vector<vector<int>>lot;
        // queue<TreeNode*>q;
        // if(root!=nullptr)q.push(root);
        // while(!q.empty()){
        //     int x=q.size();
        //     vector<int>temp;
        //     while(x--){
        //         auto a=q.front();
        //         temp.push_back(a->val);
        //         q.pop();
        //         if(a->left!=nullptr)q.push(a->left);
        //         if(a->right!=nullptr)q.push(a->right);
        //     }
        //     lot.push_back(temp);
        // }
        // for(auto it:lot)res.push_back(it.back());
        // return res;
        vector<int>res;
        queue<TreeNode*>q;
        if(root!=nullptr)q.push(root);
        while(!q.empty()){
            int x=q.size();
            int temp=0;
            while(x--){
                auto a=q.front();
                temp=a->val;
                q.pop();
                if(a->left!=nullptr)q.push(a->left);
                if(a->right!=nullptr)q.push(a->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};