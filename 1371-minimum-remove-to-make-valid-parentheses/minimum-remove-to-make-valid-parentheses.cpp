class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // remove extra close bracket
        string s1 = "";
        int open = 0;
        int close = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') open++;
            else if(s[i] == ')') close++;
            if(close > open) close--;
            else s1 += s[i];
        }

        //remove extra open bracket
        string ans = "";
        open = 0;
        close = 0;
        for(int i=s1.size()-1; i>=0; i--){
            if(s1[i] == '(') open++;
            else if(s1[i] == ')') close++;
            if(open > close) open--;
            else ans += s1[i];
        }
        cout<<ans;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};