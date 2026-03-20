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
    int solve(TreeNode* root){
        if(!root) return 0;
        return 1 + max(solve(root->left),solve(root->right));
    }

    int maxDepth(TreeNode* root) {
        // return solve(root);
        if(!root) return 0;
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                auto it = q.front();
                q.pop();
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            ans++;
        }
        return ans;
    }
};