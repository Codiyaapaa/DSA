class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        char prev = ' ';
        int cnt = 1;
        for(auto it : chars){
            if(it == prev) cnt++;
            else{
                cout<<prev<<" "<<cnt<<endl;
                if(prev != ' '){
                    chars[write++] = prev;
                    if(cnt != 1){
                        string s = to_string(cnt);
                        for (char c : s) {
                            chars[write++] = c;
                        }
                    }
                }
                cnt = 1;
                prev = it;
            }
        }
        if(prev != ' '){
            chars[write++] = prev;
            if(cnt != 1){
                string s = to_string(cnt);
                for (char c : s) {
                    chars[write++] = c;
                }
            }
        }
        cout<<prev<<" "<<cnt;
        return write;
    }
};