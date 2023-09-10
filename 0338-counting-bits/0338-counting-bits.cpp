class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1);
        result[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            // Use previously computed values to calculate the count of set bits.
            result[i] = result[i >> 1] + (i & 1);
        }
        
        return result;
    }
};
