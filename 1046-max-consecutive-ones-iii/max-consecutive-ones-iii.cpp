class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero = 0;
        int i=0;
        int j=0;
        int n=nums.size();
        int res=0;
        while(j<n){
            if(nums[j] == 0) zero++;
            while(zero > k ){
                if(nums[i] == 0) zero--;
                i++;
            }
            res = max(res,j-i+1);
            j++;
        }
        return res;
    }
};