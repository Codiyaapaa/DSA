class Solution {
public:
    int solve(vector<pair<int,int>>& count, int zero, int one, int ind, vector<vector<vector<int>>>& dp){
        if(ind >= count.size() || (one == 0 && zero == 0)) return 0;

        if(dp[ind][zero][one] != -1) return dp[ind][zero][one];

        int notpick = solve(count,zero,one,ind+1,dp);
        int pick = 0;
        if(zero >= count[ind].first && one >= count[ind].second){
            pick = 1 + solve(count,zero-count[ind].first,one-count[ind].second,ind+1,dp);
        }

        return dp[ind][zero][one] = max(pick,notpick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> count;
        for(auto it : strs){
            int zero = 0;
            int one = 0;
            for(int i=0; i<it.size(); i++){
                // cout<<it[0];
                if(it[i] == '0') zero++;
                else if(it[i] == '1') one++;
            }
            count.push_back({zero,one});
        }
        int ind = strs.size();
        vector<vector<vector<int>>> dp(ind,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        int ans = solve(count,m,n,0,dp);
        return ans;
    }
};