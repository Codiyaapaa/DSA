class Solution {
public:
    int totalMoney(int n) {
        if(n <= 7) return ((n)*(n+1))/2;
        int ans = 28; // sum from 1 to 7 (samjhe?)
        int a = n/7;
        // cout<<a<<" ";
        int b = n%7;

        int temp = 28;
        for(int i=2; i<=a; i++){
            temp += 7;
            // cout<<temp<<" ";
            ans+=temp;
        }
        cout<<ans<<" ";

        int c = a+1;
        for(int i = 1; i<=b; i++){
            // cout<<c<<" ";
            ans+=c;
            c++;
        }
        return ans;
    }
};