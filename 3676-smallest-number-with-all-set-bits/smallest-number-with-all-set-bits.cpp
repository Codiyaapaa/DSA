class Solution {
public:
    int smallestNumber(int n) {
        int digit = 0 ;
        while(n){
            n/=2;
            digit++;
        }
        //cout << digit << endl;

        int ans = 0 ;
        int a = 0 ;
        while(digit--){
            ans += pow(2 , a);
            a++;
        }
        return ans ;
    }
};