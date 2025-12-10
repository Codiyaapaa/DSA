class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                int start = j+1;
                int end = n-1;
                long long new_tar = (long long)target - (long long)nums[i] - (long long)nums[j];
                while(start < end){
                    if(new_tar == (nums[start]+nums[end])){
                        st.insert({nums[i],nums[j],nums[start],nums[end]});
                        // ans.push_back({nums[i],nums[j],nums[start],nums[end]});
                        start++;
                        end--;
                    }
                    else if(new_tar > (nums[start]+nums[end])){
                        start++;
                    }
                    else end--;
                }
            }
        }
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};