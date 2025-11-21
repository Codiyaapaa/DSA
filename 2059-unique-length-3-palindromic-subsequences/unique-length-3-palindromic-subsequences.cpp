class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // 1. use set for uniqueness
        int n = s.size();
        set<char> letter;
        for(int i=0; i<s.size(); i++) letter.insert(s[i]);

        int ans = 0;
        for(auto &l : letter){
            int left = -1;
            int right = -1;
            for(int i=0; i<n; i++){
                // cout<<s[i]<<" "<<l<<endl;
                if(s[i] == l){
                    if(left == -1) left = i;
                    right = i; 
                }
            }
        unordered_set<char> st;
        // for middle character 
        for(int j=left+1; j<right; j++){
            st.insert(s[j]);
        }
        cout<<left<<"-"<<right<<endl;
        cout<<st.size()<<endl;
        ans += st.size();
        }
        return ans;
    }
};