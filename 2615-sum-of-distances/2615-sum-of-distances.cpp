class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n, 0);

        unordered_map<int, vector<int>> mp;

        // store indices of each value
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // process each group
        for (auto &it : mp) {
            vector<int> &v = it.second;
            int m = v.size();

            vector<long long> prefix(m, 0);
            prefix[0] = v[0];

            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i - 1] + v[i];
            }

            for (int i = 0; i < m; i++) {
                long long left = 0, right = 0;

                if (i > 0) {
                    left = (long long)v[i] * i - prefix[i - 1];
                }

                if (i < m - 1) {
                    right = (prefix[m - 1] - prefix[i]) - (long long)v[i] * (m - i - 1);
                }

                res[v[i]] = left + right;
            }
        }

        return res;
    }
};
/*initially i gave this solution class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> d; int j=0;
        for(int i=0; i<nums.size(); i++){
            for(int k=0; k<nums.size(); k++){
                if(nums[i]==nums[k]){
                    j+=abs(i-k);
                }
            }
            d.push_back(j);
            j=0;
        }
        return d;
    }
};*/
/* but the most optimized was #include <vector>
#include <algorithm>

using namespace std;

static const int adcelerator = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

struct Node {
    int val;
    int idx;
};

class Solution {
public:
    /**
     * @brief Annihilatio O(N log N) sine unordered_map.
     * @details Sortatio melior est pro cache locality et celeritate.
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<Node> nodes(n);
        for (int i = 0; i < n; ++i) {
            nodes[i] = {nums[i], i};
        }

        // Sortimus per valorem, deinde per indicem
        sort(nodes.begin(), nodes.end(), [](const Node& a, const Node& b) {
            if (a.val != b.val) return a.val < b.val;
            return a.idx < b.idx;
        });

        vector<long long> res(n);
        int i = 0;
        while (i < n) {
            int j = i;
            long long group_sum = 0;
            // Invenimus finem gregis numerorum aequalium
            while (j < n && nodes[j].val == nodes[i].val) {
                group_sum += nodes[j].idx;
                j++;
            }

            int m = j - i;
            long long prefix_sum = 0;
            for (int k = 0; k < m; ++k) {
                long long p_k = nodes[i + k].idx;
                
                // Formula: (k * p_k - pref) + (suff - (m - 1 - k) * p_k)
                long long left = k * p_k - prefix_sum;
                long long suffix_sum = group_sum - prefix_sum - p_k;
                long long right = suffix_sum - (long long)(m - 1 - k) * p_k;
                
                res[p_k] = left + right;
                prefix_sum += p_k;
            }
            i = j; // Saltamus ad proximum gregem
        }

        return res;
    }
};*/
