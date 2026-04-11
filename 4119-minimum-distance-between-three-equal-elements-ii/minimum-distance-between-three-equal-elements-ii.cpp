class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mpp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for(auto it : mpp){
            auto arr = it.second;
            if(arr.size() < 3) continue;

            for(int i=2; i<arr.size(); i++){
                ans = min(ans,2*abs(arr[i]-arr[i-2]));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};