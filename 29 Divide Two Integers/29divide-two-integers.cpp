class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        int res = 0;
        bool flag = !((dividend < 0) ^ (divisor < 0)); 
        long long a = dividend;
        long long b = divisor;
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;
        while (a >= b) {
            int last_i = -1;
            long long last_product = 0;
            for (int i = 0; i < 31; i++) {
                int pow_two = 1 << i;
                long long product = (long long)pow_two * b;
                if (a >= product) {
                    last_i = i;
                    last_product = product;
                } else {
                    break;
                }
            }
            if (last_i != -1) {
                res += 1 << last_i;
                a -= last_product;
            }
        }
        return flag ? res : -res;
    }
};
