class Solution {
public:
    void solve(int n, int k, int deno, vector<int>& temp, int& diff,vector<int>& ans){
        if(k == 1){
            if(n >= deno){
                temp.push_back(n);
                check(temp,diff,ans);
                temp.pop_back();
            }
            return;
        }

        for(int i=deno; i<=n; i++){
            if(n%i == 0){
                temp.push_back(i);
                solve(n/i,k-1, i, temp,diff,ans);
                temp.pop_back();
            }
        }
    }

    void check(vector<int> temp,int& diff ,vector<int>& ans){
        int mn = *min_element(temp.begin(),temp.end());
        int mx = *max_element(temp.begin(),temp.end());
        if(mx-mn < diff){
            diff = mx - mn;
            ans = temp;
        }
        
    }

    vector<int> minDifference(int n, int k) {
        vector<int> ans;
        vector<int> temp;
        int diff = INT_MAX;
        solve(n,k,1,temp,diff,ans);
        return ans;
    }
};