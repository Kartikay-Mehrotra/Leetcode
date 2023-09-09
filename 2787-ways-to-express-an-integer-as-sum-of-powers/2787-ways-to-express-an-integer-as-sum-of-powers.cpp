class Solution {
    long long dfs(int i, int n, int x, int mod, vector<vector<int>> &dp, int N) {
        if(n==0) return 1;
        if(i > N) return 0;
        if(dp[i][n] != -1) return dp[i][n];
        
        long long notpick = dfs(i + 1, n, x, mod, dp, N);
        long long pick = n - pow(i, x) >= 0 ? dfs(i + 1, n - pow(i, x), x, mod, dp, N) : 0;
        
        return dp[i][n] = (pick + notpick) % mod;
    }
public:
    int numberOfWays(int n, int x) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return dfs(1, n, x, mod, dp, n);
    }
};