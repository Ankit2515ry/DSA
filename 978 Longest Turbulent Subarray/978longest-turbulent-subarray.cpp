class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;

        int ans = 1;
        int j = 0;

        for (int i = 1; i < n; i++) {
            int c = (arr[i-1] < arr[i] ? -1 : (arr[i-1] > arr[i] ? 1 : 0));

            if (c == 0) {
                j = i;
            } 
            else if (i == n - 1 || c * (arr[i] < arr[i+1] ? -1 : (arr[i] > arr[i+1] ? 1 : 0)) != -1) {
                ans = max(ans, i - j + 1);
                j = i;
            }
        }

        return ans;
    }
};
