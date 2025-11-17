class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt = 0;
        bool flag = false;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) cnt++;
            else{
                cout<<cnt<<" ";
                if(flag && cnt < k) return false;
                flag = true;
                cnt = 0;
            }
        }
        return true;
    }
};