class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int rem = 0;
        int i=0;
        int j=0;
        int n=nums.size();
        int res=0;
        while(j<n){
            if(nums[j]==0) rem++;
            while(rem>1){
                if(nums[i] == 0) rem--;
                i++;
            }
            res = max(res,j-i);
            j++;
        }
        return res;
    }
};