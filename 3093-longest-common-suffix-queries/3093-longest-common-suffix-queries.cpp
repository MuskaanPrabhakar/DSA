class Solution {
public:
    struct Node {
        int child[26];
        int bestIdx, bestLen;

        Node() {
            memset(child, -1, sizeof(child));
            bestIdx = -1;
            bestLen = INT_MAX;
        }
    };

    vector<Node> trie;

    Solution() {
        trie.reserve(500005); // avoid reallocations
        trie.push_back(Node()); // root
    }

    void updateBest(int node, int idx, int len) {
        if (len < trie[node].bestLen ||
           (len == trie[node].bestLen &&
            (trie[node].bestIdx == -1 || idx < trie[node].bestIdx))) {

            trie[node].bestLen = len;
            trie[node].bestIdx = idx;
        }
    }

    void insert(const string& word, int idx) {
        int node = 0;
        int len = word.size();

        // Empty suffix candidate
        updateBest(node, idx, len);

        for (int i = len - 1; i >= 0; i--) {
            int c = word[i] - 'a';

            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(Node());
            }

            node = trie[node].child[c];
            updateBest(node, idx, len);
        }
    }

    int query(const string& word) {
        int node = 0;

        for (int i = word.size() - 1; i >= 0; i--) {
            int c = word[i] - 'a';

            if (trie[node].child[c] == -1) {
                break;
            }

            node = trie[node].child[c];
        }

        return trie[node].bestIdx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i);
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());

        for (const string& q : wordsQuery) {
            ans.push_back(query(q));
        }

        return ans;
    }
};