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
    int height(TreeNode* root){
        if(!root) return 0;
        queue<TreeNode*> st;
        st.push(root);
        int ht = 0;
        while(!st.empty()){
            int size = st.size();
            for(int i=0; i<size; i++){
                TreeNode* node = st.front();
                st.pop();
                if(node->left) st.push(node->left);
                if(node->right) st.push(node->right);
            }
            ht++;
        }
        return ht;
    }

    // int height(TreeNode* root){
    //     if(!root) return 0;
    //     int left = height(root->left);
    //     int right = height(root->right);
    //     if(abs(left-right) > 1) return -1;
    //     if(left == -1 || right == -1) return -1;
    //     return 1 + max(left,right);
    // }

    bool isBalanced(TreeNode* root) {
        if(!root) return 1;
        int left = height(root->left);
        int right = height(root->right);
        cout<<abs(left-right)<<" ";
        if(abs(left-right) > 1) return 0;
        bool left1 = isBalanced(root->left);
        bool right1 = isBalanced(root->right);
        if(!left1 || !right1) return false;
        return true;

        if(height(root) != -1) return true;
        return false;
    }
};