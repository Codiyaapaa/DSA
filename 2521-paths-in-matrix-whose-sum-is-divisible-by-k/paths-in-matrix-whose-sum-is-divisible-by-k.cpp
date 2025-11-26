class Solution {
public:
    int mod = 1000000007;

    int solve(int i, int j, int m, int n, vector<vector<int>>& grid, int k, int sum,vector<vector<vector<int>>>& dp){
        if(i < 0 || j < 0 || i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) {
            if((sum + grid[i][j]) % k == 0) return 1;
            return 0;
        }

        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        int right = 0;
        int down = 0;
        if(j+1 < n) right = solve(i,j+1,m,n,grid,k,(sum+grid[i][j])%k,dp);
        if(i+1 < m) down = solve(i+1,j,m,n,grid,k,(sum+grid[i][j])%k,dp);

        return dp[i][j][sum] = (right+down)%mod;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp (m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return solve(0,0,m,n,grid,k,0,dp);
    }
};