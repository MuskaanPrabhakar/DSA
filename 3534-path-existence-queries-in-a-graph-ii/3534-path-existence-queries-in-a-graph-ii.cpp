class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> ord;
        ord.reserve(n);
        for(int i=0;i<n;i++)
            ord.push_back({nums[i], i});

        sort(ord.begin(), ord.end());

        vector<int> pos(n);
        vector<int> comp(n);

        vector<int> nextPos(n);

        int LOG = 18;      // 2^17 > 1e5
        vector<vector<int>> up(LOG, vector<int>(n));

        int cid = 0;

        int start = 0;

        while(start < n){

            int end = start;
            while(end + 1 < n &&
                  ord[end + 1].first - ord[end].first <= maxDiff)
                end++;

            // assign position/component
            for(int i=start;i<=end;i++){
                pos[ord[i].second] = i;
                comp[ord[i].second] = cid;
            }

            // two pointers for next
            int j = start;
            for(int i=start;i<=end;i++){
                while(j+1<=end &&
                      ord[j+1].first - ord[i].first <= maxDiff)
                    j++;
                nextPos[i] = j;
                if(j<i) j=i;
            }

            cid++;
            start = end + 1;
        }

        for(int i=0;i<n;i++)
            up[0][i] = nextPos[i];

        for(int k=1;k<LOG;k++){
            for(int i=0;i<n;i++){
                up[k][i] = up[k-1][ up[k-1][i] ];
            }
        }

        vector<int> ans;

        for(auto &q: queries){

            int u = q[0];
            int v = q[1];

            if(comp[u] != comp[v]){
                ans.push_back(-1);
                continue;
            }

            int l = pos[u];
            int r = pos[v];

            if(l == r){
                ans.push_back(0);
                continue;
            }

            if(l > r) swap(l,r);

            int cur = l;
            int res = 0;

            for(int k=LOG-1;k>=0;k--){
                if(up[k][cur] < r){
                    cur = up[k][cur];
                    res += (1<<k);
                }
            }

            ans.push_back(res + 1);
        }

        return ans;
    }
};