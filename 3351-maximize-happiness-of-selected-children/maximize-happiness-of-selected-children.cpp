class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int i =0;
        sort(happiness.rbegin(),happiness.rend());
        long long res = 0;
        while(k != 0){
            if(happiness[i]-i > 0) res += happiness[i]-i;
            i++;
            k--;
        }
        return res;
    }
};