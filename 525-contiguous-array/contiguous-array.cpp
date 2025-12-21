class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        int cnt = 0;
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 1) cnt++;
            else cnt--;
            if(mpp.find(cnt) != mpp.end()){
                ans = max(ans,i-mpp[cnt]);
            }
            else mpp[cnt] = i;
        }
        return ans;
    }
};