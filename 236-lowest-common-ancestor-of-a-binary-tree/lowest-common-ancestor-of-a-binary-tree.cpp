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
        TreeNode* ans = NULL;
        int mini = min(path1.size(),path2.size());
        for(int i=0; i<mini; i++){
            if(path1[i] == path2[i]) ans = path1[i];
            else break;
        }
        return ans;
    }
};