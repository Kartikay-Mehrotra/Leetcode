class Solution {
public:
    int countOrders(int n) {
        long long mod = 1e9 + 7;
        int i = 1, t = 6, x = 9;
        long long ans = 1;

        while(i < n) {
            ans = (ans * t) % mod;

            t = (t + x) % mod;
            x += 4;
            i++;
        }
        return ans;
    }
};