class Solution {
public:
    void solve(int ind, vector<vector<int>>& ans, vector<int> temp, vector<int>& cand, int target){
        if(ind == cand.size() || target == 0){
            if(target == 0) ans.push_back(temp);
            return;
        }

        for(int i=ind; i<cand.size(); i++){
            if(i > ind && cand[i] == cand[i-1]) continue;
            if(cand[ind] > target) break;
            temp.push_back(cand[i]);
            solve(i+1,ans,temp,cand,target - cand[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        solve(0,ans,temp,candidates,target);
        return ans;
    }
};