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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*>q;
        bool flag = true;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> lvl(n);

            for(int i=0; i<n; i++){
                auto it = q.front();
                q.pop();
                int ind = i;
                if(flag == false){
                    ind = n - 1 - i;
                }
                lvl[ind] = it->val;
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            ans.push_back(lvl);
            flag = !flag;
        }
        return ans;
    }
};