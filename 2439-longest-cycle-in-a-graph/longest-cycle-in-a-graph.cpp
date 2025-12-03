class Solution {
public:
    bool dfs(int len,int node, int& ans, vector<int>& vis, vector<int>& path,vector<int>& edges){
        len++;
        vis[node] = 1;
        path[node] = len;

        int new_node = edges[node];
        if(new_node != -1){
            if(!vis[new_node]){
                if(dfs(len,new_node,ans,vis,path,edges)) return true;
            }
            else if(path[new_node] != 0){
                int len = path[node] - path[new_node] + 1;
                ans = max(ans,len);
            }
        }
        path[node] = 0;
        return false;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n+1,0);
        vector<int> path(n+1,0);
        int ans = -1;
        for(int i=0; i<n; i++){
            if(!vis[i]) dfs(0,i,ans,vis,path,edges);
        }
        return ans;
    }
};