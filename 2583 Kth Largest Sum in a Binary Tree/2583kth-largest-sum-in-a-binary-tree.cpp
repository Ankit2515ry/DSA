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
    long long kthLargestLevelSum(TreeNode* root, int z) {
        vector<long long>temp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int k=q.size();
            long long sum=0;
            while(k--){
                TreeNode* n=q.front();
                q.pop();
                sum+=n->val;
                if(n->left)q.push(n->left);
                if(n->right)q.push(n->right);
            }
            temp.push_back(sum);
        }
        if(z>temp.size())return -1;
        sort(temp.rbegin(),temp.rend());
        long long res=temp[z-1];
        return res;
    }
};