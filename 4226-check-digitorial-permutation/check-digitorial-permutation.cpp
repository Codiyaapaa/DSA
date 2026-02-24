class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<long long> arr(10);
        vector<int> freq(10);
        arr[0] = 1;
        for(int i=1; i<10; i++){
            arr[i] = arr[i-1]*i;
        }
        long long ans = 0;
        while(n){
            int num = n%10;
            freq[num]++;
            ans += arr[num];
            // if(ans > temp) return false;
            n = n/10;
        }
        while(ans){
            int num = (ans%10);
            freq[num]--;
            ans /= 10;
        }

        for(auto it : freq){
            if(it != 0) return false;
        }
        return true;
    }
};