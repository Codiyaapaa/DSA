class Solution {
public:
    int solve(vector<int>& quantities, int range){
        int op = 0;
        for(auto it : quantities){
            if(it%range) op += (it/range)+1;
            else op += it/range;
        }
        return op;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(),quantities.end());
        while(low < high){
            int mid = low + (high - low)/2;
            if(solve(quantities,mid) <= n) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};