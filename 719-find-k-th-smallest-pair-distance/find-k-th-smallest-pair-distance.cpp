class Solution {
public:
    int count(vector<int>& nums, int mid){
        int left = 0;
        int cnt = 0;
        for(int right=0; right < nums.size(); right++){
            while(nums[right]-nums[left] > mid) left++;
            cnt += right - left;
        }
        return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int low = 0;
        int high = nums.back()-nums.front();

        while(low < high){
            int mid = low + (high - low)/2;
            if(count(nums,mid) >= k) high = mid ;
            else low = mid + 1;
        }
        return low;
    }
};