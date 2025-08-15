/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path(TreeNode* root, int x, vector<TreeNode*>& paths){
        if(!root) return false;
        paths.push_back(root);

        if(root->val == x) return true;

        if(path(root->left,x,paths) || path(root->right,x,paths)) return true;
        paths.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        path(root,p->val,path1);
        path(root,q->val,path2);
        for(auto it: path1) cout<<it->val<<" ";
        cout<<endl;
        for(auto it: path2) cout<<it->val<<" ";
        TreeNode* ans = root;
        int i = 0;
        int j = 0;
        int n = path1.size();
        int m = path2.size();
        while(i<n && j<m){
            if(path1[i] == path2[j]) ans = path1[i];
            i++;
            j++;
        }
        return ans;
    }
};