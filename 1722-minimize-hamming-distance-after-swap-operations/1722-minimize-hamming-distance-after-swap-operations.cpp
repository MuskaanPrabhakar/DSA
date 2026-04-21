class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        
        int n = source.size();
        
        // Step 1: DSU (Union-Find)
        vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        
        function<int(int)> find = [&](int x) {
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        };
        
        auto unite = [&](int a, int b) {
            parent[find(a)] = find(b);
        };
        
        // Step 2: connect indices
        for(auto &p : allowedSwaps) {
            unite(p[0], p[1]);
        }
        
        // Step 3: count values in each group
        unordered_map<int, unordered_map<int,int>> mp;
        
        for(int i = 0; i < n; i++) {
            int root = find(i);
            mp[root][source[i]]++;
        }
        
        // Step 4: match with target
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int root = find(i);
            
            if(mp[root][target[i]] > 0) {
                mp[root][target[i]]--;
            } else {
                ans++;
            }
        }
        
        return ans;
    }
};