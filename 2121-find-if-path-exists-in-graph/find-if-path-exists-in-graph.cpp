class Solution {
public:
    void bfs(int source, vector<int>& vis, vector<int> adj[]){
        vis[source] = 1;
        queue<int> q;
        q.push(source);

        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto it : adj[top]){
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    void dfs(int source, vector<int>& vis, vector<int> adj[]){
        vis[source] = 1;

        for(auto it : adj[source]){
            if(!vis[it]) dfs(it,vis,adj);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(auto it : edges){
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> vis(n,0);
        dfs(source,vis,adj);
        // bfs(source,vis,adj);
        return vis[destination];
    }
};