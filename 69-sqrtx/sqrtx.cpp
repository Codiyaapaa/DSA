class Solution {
public:
    int mySqrt(int x) {
        int i=0;
        int j=x;
        int ans = 0;
        while(j>=i){
            long long mid = (i+j)/2;
            // cout<<mid<<" ";
            if(mid*mid == x) return mid;
            else if(mid*mid < x){
                ans = mid;
                i = mid+1;
            }
            else j = mid-1;
        }
        return ans;
    }
};