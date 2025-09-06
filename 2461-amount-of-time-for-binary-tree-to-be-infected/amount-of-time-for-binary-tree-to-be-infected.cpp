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
    void inorder(TreeNode* root, int start,TreeNode*& target){
        if(!root) return;
        if(root->val == start){
            target = root;
            return;
        }
        inorder(root->left,start,target);
        inorder(root->right,start,target);
    }

    void make_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto curr = q.front();
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

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        make_parent(root,parent);
        // for(auto it : parent) cout<<it.first->val<<" "<<it.second->val<<endl;
        TreeNode* target;
        inorder(root,start,target);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                    cout<<curr->left->val<<" ";
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                    cout<<curr->right->val<<" ";
                }
                if(parent[curr] && !vis[parent[curr]]){
                    q.push(parent[curr]);
                    vis[parent[curr]] = true;
                    cout<<parent[curr]->val<<" ";
                }
            }
            cout<<endl;
            ans++;
        }
        // cout<<target->val;
        return ans-1;
    }
};