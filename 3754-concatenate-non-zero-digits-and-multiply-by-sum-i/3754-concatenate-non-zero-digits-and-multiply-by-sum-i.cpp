class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long p = 1;
        int sum = 0;

        while (n > 0) {
            int d = n % 10;
            if (d != 0) {
                x += 1LL * d * p;
                p *= 10;
                sum += d;
            }
            n /= 10;
        }

        return x * sum;
    }
};