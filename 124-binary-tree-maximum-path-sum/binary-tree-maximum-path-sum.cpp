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
    int solve(TreeNode* root, int& maxi){
        if(!root) return 0;
        int lt = max(0,solve(root->left,maxi));
        int rt = max(0,solve(root->right,maxi));
        maxi = max(maxi,root->val+lt+rt);
        return root->val+max(lt,rt);
    }

    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        if(root->left == NULL && root->right == NULL) return root->val;
        int maxi = INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};