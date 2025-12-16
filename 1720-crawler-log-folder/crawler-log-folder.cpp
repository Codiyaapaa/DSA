class Solution {
public:
    int minOperations(vector<string>& logs) {
        string st = "";
        for(auto it : logs){
            if(st.size() > 0 && it == "../") st.pop_back();
            else if(it == "./" || it == "../") continue;
            else st.push_back('#');
        }
        for(auto it : st) cout<<it<<" ";
        return st.size();
    }
};