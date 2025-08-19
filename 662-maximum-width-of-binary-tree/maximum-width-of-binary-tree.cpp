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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            int mini = q.front().second;
            int x = q.front().second;
            int y = q.back().second;
            ans = max(ans,y-x+1);
            for(int i=0;i<size; i++){
                TreeNode* node = q.front().first;
                long long cnt = q.front().second-mini;
                // cout<<q.front().first->val<<"->"<<q.front().second<<" ";
                q.pop();
                // cout<<endl<<x<<" "<<y<<endl;
                if(node->left) q.push({node->left,(cnt)*2+1});
                if(node->right) q.push({node->right,2*cnt+2});
            }
            // cout<<endl;
        }
        return ans;
    }
};