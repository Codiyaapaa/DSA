class Solution {
public:
    long long split(int mid,vector<int>& piles){
        long long cnt = 0;
        for(auto it : piles){
            cnt += ceil(double(it)/mid);
        }
        return cnt;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        long long high = 0;
        for(auto it : piles) high += it;
        while(low<high){
            long long mid = low + (high - low)/2;
            if(split(mid,piles) <= h) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};