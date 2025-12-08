class Solution {
public:
    vector<vector<long long>> multiply(vector<vector<long long>>& A, vector<vector<long long>>& B) {
        vector<vector<long long>> C(3, vector<long long>(3));
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    C[i][j] += A[i][k] * B[k][j];
        return C;
    }
    vector<vector<long long>> matPow(vector<vector<long long>> M, long long n) {
        vector<vector<long long>> R = {{1,0,0},{0,1,0},{0,0,1}}; // Identity
        while (n > 0) {
            if (n & 1) R = multiply(R, M);
            M = multiply(M, M);
            n >>= 1;
        }
        return R;
    }
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        vector<vector<long long>> M = {
            {1,1,1},
            {1,0,0},
            {0,1,0}
        };
        vector<vector<long long>> R = matPow(M, n - 1);
        return R[0][0];
    }
};