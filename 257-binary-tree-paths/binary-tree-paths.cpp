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
    void solve(TreeNode* root, string str, vector<string>& ans){
        if(!root) return;
        if(str == ""){
            str = to_string(root->val);
        }
        else str += "->" + to_string(root->val);
        if(root->left == NULL && root->right == NULL) ans.push_back(str);
        solve(root->left,str,ans);
        solve(root->right,str,ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> ans;
        solve(root,"",ans);
        return ans;
    }
};