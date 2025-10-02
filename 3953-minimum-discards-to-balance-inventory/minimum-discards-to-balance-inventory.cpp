class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n = arrivals.size();
        int ans = 0;
        vector<int> discard(n,0);
        unordered_map<int,int> freq;
        for(int i=0; i<min(n,w); i++){
            freq[arrivals[i]]++;
            if(freq[arrivals[i]] > m){
                freq[arrivals[i]]--;
                discard[i] = 1;
                ans++;
            }
        }
        for(int i=w; i<n; i++){
            freq[arrivals[i]]++;
            if(freq[arrivals[i-w]] > 0 && discard[i-w] == 0){
                freq[arrivals[i-w]]--;
            }

            if(freq[arrivals[i]] > m){
                freq[arrivals[i]]--;
                discard[i] = 1;
                ans++;
            }
        }
        // for(auto it : discard) cout<<it<<" ";
        return ans;
    }
};