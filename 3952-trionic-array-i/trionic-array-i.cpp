class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if(nums[0] >= nums[1]) return false;
        int n = nums.size(); 
        int i =0;
        bool p=false;
        bool q = false;
        //for increase
        while(i<n-1 && nums[i] < nums[i+1]){
            p = true;
            i++;
        }
        cout<<i<<endl;
        while(i<n-1 && nums[i] > nums[i+1]){
            q = true;
            i++;
        }
        cout<<i<<endl;
        while(i<n-1){
            if(nums[i] >= nums[i+1] ) return false;
            i++;
        }
        cout<<p<<" "<<q;
        if(nums[n-2] >= nums[n-1]) return false;
        if(p && q) return true;
        return false;
        bool inc = 0;
        // for(i; i<n-2; i++){
        //     // if(nums[i] == nums[i+1]) return false;
        //     if(nums[i] > nums[i+1]){
        //         // dec++;
        //         // break;
        //     }
        //     else dec = 0;
        // }
        // if(dec > 1) return false;
        return true;
    }
};