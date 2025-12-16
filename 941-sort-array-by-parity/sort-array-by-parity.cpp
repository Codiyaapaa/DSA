class Solution {
public:
    static bool cmp(int a, int b){
        return a%2 < b%2;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        // sort(nums.begin(),nums.end(),cmp);
        // return nums;
        int n = nums.size();
        int even = 0;
        int odd = n-1;
        while(even < odd){
            while(even<n && nums[even]%2==0) even++;
            while(odd>=0 && nums[odd]%2==1) odd--;
            // cout<<even<<" "<<odd<<endl;
            // cout<<nums[even]<<" "<<nums[odd]<<endl;
            if(even < odd) swap(nums[even++],nums[odd--]);
        }
        return nums;
    }
};