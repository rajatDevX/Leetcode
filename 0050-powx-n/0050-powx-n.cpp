class Solution {
public:
    double myPow(double x, int n) {

        long long N = n;

        bool negative = false;

        if (N < 0) {
            negative = true;
            N = -N;
        }

        double ans = 1;

        while (N > 0) {

            if (N % 2 == 1) {
                ans = ans * x;
            }

            x = x * x;
            N = N / 2;
        }

        if (negative) {
            return 1 / ans;
        }

        return ans;
    }
};