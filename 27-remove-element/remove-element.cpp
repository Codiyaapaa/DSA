class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int write = 0;
        int n = nums.size();
        for(int read=0; read<n; read++){
            if(nums[read] != val){
                nums[write] = nums[read];
                write++;
            }
        }
        return write;
    }
};