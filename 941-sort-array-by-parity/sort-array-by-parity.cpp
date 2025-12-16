class Solution {
public:
    static bool cmp(int a, int b){
        return a%2 < b%2;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        return nums;
    }
};