class Solution {
public:
    vector<int> jumps = {-1, 0, 1};
    vector<vector<int>> memo; // Memoization table
    
    bool solve(int idx, vector<int>& s, int prev) {
        if (idx >= s.size())
            return false;
        
        if (idx == s.size() - 1)
            return true;
        
        if (memo[idx][prev] != -1)
            return memo[idx][prev];
        
        bool po = false;
        for (int i = 0; i < 3; i++) {
            int newj = prev + jumps[i];
            for (int j = idx + 1; j < s.size(); j++) {
                if (s[idx] + newj == s[j]) {
                    
                    if ( solve(j, s, newj)) {
                        return memo[idx][prev] = true; 
                        //return true;
                    }
                }
            }
        }
        
        return memo[idx][prev] = po; 
        //return po;
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] > 1)
            return false;
        
        int n = stones.size();
        memo.resize(n, vector<int>(n, -1)); // Initialize the memo table with -1
        
        return solve(1, stones, 1);
    }
};
