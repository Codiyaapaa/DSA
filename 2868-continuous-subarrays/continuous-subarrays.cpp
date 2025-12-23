class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> mini;
        deque<int> maxi;
        int n = nums.size();
        int i=0;
        int j=0;
        long long ans = 0;
        while(j<n){
            while(!mini.empty() && nums[mini.back()] > nums[j]) mini.pop_back();
            while(!maxi.empty() && nums[maxi.back()] < nums[j]) maxi.pop_back();
            mini.push_back(j);
            maxi.push_back(j);
            while(nums[maxi.front()] - nums[mini.front()] > 2){
                if(mini.front() == i) mini.pop_front();
                if(maxi.front() == i) maxi.pop_front();
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
};