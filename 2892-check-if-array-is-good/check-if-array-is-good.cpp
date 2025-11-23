class Solution {
public:
    bool isGood(vector<int>& nums) {
        //1st find the maximum
        int n = nums.size();
        int maxi = 0;
        int sum1 = 0;
        unordered_map<int, int> mpp;
        for(auto it : nums){
            // sum1+=it;
            maxi = max(maxi,it);
            mpp[it]++;
        }
        if(maxi != (nums.size() - 1)) return false;
        if(mpp[maxi] != 2) return false;
        // cout<<maxi<<;
        for(auto it : nums){
            if(it != maxi && mpp[it] > 1) return false; 
        }
        // int sum = (n*(n-1)/2)+maxi; 
        // return sum==sum1;
        return true;
    }
};