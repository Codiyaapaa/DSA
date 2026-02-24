class Solution {
public:
    string maximumXor(string s, string t) {
        int n = t.size();
        int one = 0;
        for(auto it : t) if(it == '1') one++;
        int zero = n - one;
        string ans = "";
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                if(one){
                    ans += '1';
                    one--;
                }
                else{
                    ans += '0';
                    zero--;
                }
            }
            else{
                if(zero){
                    ans+= '1';
                    zero--;
                }
                else{
                    ans+= '0';
                    one--;
                }
            }
        }
        return ans;
    }
};