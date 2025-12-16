class Solution {
public:
    void solve(string &s, int left, int right, int& cnt){
        int n = s.size();
        while(left>=0 && right<n && s[left] == s[right]){
            cnt++;
            left--;
            right++;
        }
    }

    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            //for odd
            solve(s,i,i,cnt);

            //for even
            solve(s,i,i+1,cnt);
        }
        return cnt;
    }
};