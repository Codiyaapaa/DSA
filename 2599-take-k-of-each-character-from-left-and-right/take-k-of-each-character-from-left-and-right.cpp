class Solution {
public:
    int takeCharacters(string s, int k) {
        int total_a = 0;
        int total_b = 0;
        int total_c = 0;
        for(auto it : s){
            if(it == 'a') total_a++;
            else if(it == 'b') total_b++;
            else total_c++;
        }
        if (total_a < k || total_b < k || total_c < k) return -1;
        int n = s.size();
        int i=0;
        int j=0;
        int len = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        while(j<n){
            if(s[j] == 'a') a++;
            else if(s[j] == 'b') b++;
            else c++;

            while(a > total_a - k || b > total_b - k || c > total_c - k){
                if(s[i] == 'a') a--;
                else if(s[i] == 'b') b--;
                else c--;
                i++;
            }

            len = max(len,j-i+1);
            j++;
        }
        return n-len;
    }
};