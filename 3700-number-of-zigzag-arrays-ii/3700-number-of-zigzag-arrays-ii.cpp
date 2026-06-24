class Solution {
public:
    static constexpr long long MOD = 1'000'000'007LL;

    using Matrix = vector<vector<long long>>;

    // Matrix multiplication
    Matrix multiply(const Matrix& A, const Matrix& B) {
        int sz = A.size();
        Matrix C(sz, vector<long long>(sz, 0));

        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < sz; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] +
                               A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    // Fast matrix exponentiation
    Matrix matPow(Matrix base, long long exp) {
        int sz = base.size();

        Matrix res(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++)
            res[i][i] = 1; // Identity matrix

        while (exp > 0) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m; // up[0..m-1], down[0..m-1]

        // Base state for length = 2
        vector<long long> state(sz, 0);

        // state[0..m-1]     -> up
        // state[m..2m-1]    -> down
        for (int x = 0; x < m; x++) {
            state[x] = x;             // up[x] = x (x smaller values)
            state[m + x] = m - 1 - x; // down[x]
        }

        // Build transition matrix T
        Matrix T(sz, vector<long long>(sz, 0));

        // newUp[y] = sum down[x], x < y
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < y; x++) {
                T[y][m + x] = 1;
            }
        }

        // newDown[y] = sum up[x], x > y
        for (int y = 0; y < m; y++) {
            for (int x = y + 1; x < m; x++) {
                T[m + y][x] = 1;
            }
        }

        // Need T^(n-2)
        Matrix P = matPow(T, n - 2);

        // Multiply P * state
        vector<long long> finalState(sz, 0);

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (P[i][j] == 0) continue;

                finalState[i] =
                    (finalState[i] + P[i][j] * state[j]) % MOD;
            }
        }

        long long ans = 0;
        for (long long val : finalState)
            ans = (ans + val) % MOD;

        return (int)ans;
    }
};