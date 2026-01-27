class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(auto it : num){
            while(k>0 && !st.empty() && st.top() > it){
                k--;
                st.pop();
            }
            st.push(it);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int zero = 0;
        while(ans[zero] == '0') zero++;
        ans = ans.substr(zero);
        if(ans.size() == 0) return "0";
        return ans;
    }
};