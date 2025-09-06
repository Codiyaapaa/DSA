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
    void mark_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        mark_parent(root,parent);
        // for(auto it : parent) cout<<it.first->val<<" "<<it.second->val<<endl;
        int lvl = 0;
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;
        vis[target] = true;
        q.push(target);
        while(!q.empty()){
            if(lvl == k) break;
            int size = q.size();
            for(int i=0; i<size; i++){
                auto curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(parent[curr] && !vis[parent[curr]]){
                    q.push(parent[curr]);
                    vis[parent[curr]] = true;
                }
            }
            lvl++;
        }
        vector<int> ans;
        while(!q.empty()){
            auto valu = q.front();
            q.pop();
            ans.push_back(valu->val);
        }
        return ans;
    }
};