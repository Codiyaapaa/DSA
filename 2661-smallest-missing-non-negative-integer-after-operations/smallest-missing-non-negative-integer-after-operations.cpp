class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> mpp;
        for(auto it : nums){
            int val = ((it%value)+value)%value;
            mpp[val]++;
        }
        int MEX = 0;
        while(mpp[(MEX%value)] > 0){
            mpp[(MEX%value)]--;
            MEX++;
        }
        return MEX;
    }
};