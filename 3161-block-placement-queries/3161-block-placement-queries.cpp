class Solution {
public:
    class SegmentTree {
    public:
        int n;
        vector<int> tree;

        SegmentTree(int size) {
            n = size;
            tree.resize(4 * n, 0);
        }

        void update(int idx, int val, int node, int left, int right) {
            if (left == right) {
                tree[node] = val;
                return;
            }

            int mid = (left + right) / 2;

            if (idx <= mid) {
                update(idx, val, 2 * node, left, mid);
            } else {
                update(idx, val, 2 * node + 1, mid + 1, right);
            }

            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }

        void update(int idx, int val) {
            update(idx, val, 1, 0, n - 1);
        }

        int query(int ql, int qr, int node, int left, int right) {
            if (qr < left || right < ql) {
                return 0;
            }

            if (ql <= left && right <= qr) {
                return tree[node];
            }

            int mid = (left + right) / 2;

            return max(
                query(ql, qr, 2 * node, left, mid),
                query(ql, qr, 2 * node + 1, mid + 1, right)
            );
        }

        int query(int left, int right) {
            return query(left, right, 1, 0, n - 1);
        }
    };

    vector<bool> getResults(vector<vector<int>>& queries) {
        const int MAX_X = 50000;

        // Store all obstacles first
        set<int> obstacles;

        for (auto &q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            }
        }

        // Active obstacle set
        set<int> s;
        s.insert(0);
        s.insert(MAX_X);

        for (int x : obstacles) {
            s.insert(x);
        }

        SegmentTree seg(MAX_X + 1);

        // Build initial gaps
        int prevPos = 0;
        auto it = std::next(s.begin());

        while (it != s.end()) {
            int x = *it;

            seg.update(x, x - prevPos);

            prevPos = x;
            ++it;
        }

        vector<bool> ans;

        // Process queries in reverse
        for (int i = queries.size() - 1; i >= 0; i--) {

            auto &q = queries[i];

            // Reverse of insertion = removal
            if (q[0] == 1) {
                int x = q[1];

                auto it = s.find(x);

                int prevObs = *std::prev(it);
                int nextObs = *std::next(it);

                // Merge interval
                seg.update(nextObs, nextObs - prevObs);

                s.erase(it);

                // Remove old gap entry
                seg.update(x, 0);
            }

            // Type 2 query
            else {
                int x = q[1];
                int sz = q[2];

                auto it = s.upper_bound(x);
                --it;

                int prevObs = *it;

                // Best stored gap
                int bestGap = seg.query(0, x);

                // Gap from last obstacle to x
                int tailGap = x - prevObs;

                int maxPossible = max(bestGap, tailGap);

                ans.push_back(maxPossible >= sz);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};