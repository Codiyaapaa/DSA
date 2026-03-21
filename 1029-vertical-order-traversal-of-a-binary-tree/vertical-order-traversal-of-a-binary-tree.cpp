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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // map<int,map<int,multiset<int>>> nodes;
        // queue<pair<TreeNode*, pair<int,int>>> pq;
        // pq.push({root,{0,0}});
        // while(!pq.empty()){
        //     auto p = pq.front();
        //     pq.pop();
        //     TreeNode* node = p.first;
        //     int x = p.second.first;
        //     int y = p.second.second;
        //     nodes[x][y].insert(node->val);
        //     if(node->left) pq.push({node->left,{x-1,y+1}});
        //     if(node->right) pq.push({node->right,{x+1,y+1}});
        // }

        // vector<vector<int>> ans;
        // for(auto layer1 : nodes){
        //     vector<int> col;
        //     for(auto layer2 : layer1.second){
        //         col.insert(col.end(),layer2.second.begin(),layer2.second.end());
        //     }
        //     ans.push_back(col);
        // }
        // return ans;

        map<int,map<int,priority_queue<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int x = it.second.first;
            int y = it.second.second;
            nodes[x][y].push(node->val*-1);
            if(node->left) q.push({node->left,{x-1,y+1}});
            if(node->right) q.push({node->right,{x+1,y+1}});
        }
        vector<vector<int>> ans;

        for(auto it : nodes){
            cout<<it.first<<" ";
            vector<int> temp;
            for(auto it2 : it.second){
                while(!it2.second.empty()){
                    temp.push_back(it2.second.top()*-1);
                    it2.second.pop();
                }
            }
                ans.push_back(temp);
        }

        return ans;
    }
};