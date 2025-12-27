class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int n=nums.size();
        while(i<j){
            int mid = i+(j-i)/2;
            if(mid%2) mid--;
            if(nums[mid] == nums[mid+1]) i = mid + 2;
            else j = mid;
        }
        return nums[i];
    }
};