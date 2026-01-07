class Solution {
public:
    int bloom(vector<int>& bloomDay, int mid, int k){
        int cnt = 0;
        int res = 0;
        for(auto it : bloomDay){
            if(it <= mid) cnt++;
            else{
                res += (cnt/k);
                cnt = 0;
            }
        }
        res += (cnt/k);
        return res;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long t = 1LL*m*k;
        if(n<t) return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        while(low < high){
            int mid = low + (high - low)/2;
            if(bloom(bloomDay,mid,k) >= m) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};