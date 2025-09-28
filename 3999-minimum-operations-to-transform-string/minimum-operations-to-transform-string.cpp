class Solution {
public:
    int minOperations(string s) {
        char mini = 'z';
        char maxi = 'a';
        for(auto it : s){
            if(it != 'a'){
                if(it < mini) mini = it;
                if(it > maxi) maxi = it;
            }
        }
        int val = maxi-mini;
        if(val < 0) return 0;
        val += (26 - (maxi - 'a'))%26;
        cout<<val<<endl;
        // while(st.size() != 1){
        //     auto first = st.begin();
        //     cout<<*first<<" ";
        //     st.erase(*first);
        // }
        // for(auto it : st) cout<<it<<" ";
        return val;
    }
};