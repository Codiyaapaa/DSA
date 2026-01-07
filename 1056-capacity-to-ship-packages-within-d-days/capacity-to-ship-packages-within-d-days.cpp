class Solution {
public:
    int count(int mid, vector<int>& weights){
        int sum = 0;
        int day = 1;
        for(int it : weights){
            if(it > mid) return INT_MAX;
            if((sum+it) > mid){
                sum = it;
                day++;
            }
            else sum+=it;
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MAX;
        int high = 0;
        for(int it : weights){
            low = min(low,it);
            high += it;
        }
        while(low < high){
            int mid = low + (high - low)/2;
            if(count(mid,weights)<=days) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};