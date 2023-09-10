class Solution {
public:
    int maxProduct(vector<int>& v) {
        int pre = 1, suff = 1, maxi = INT_MIN, n = v.size();
        for(int i = 0; i < n; i++) {
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;
            pre = pre * v[i];
            suff = suff * v[n - i - 1];
            maxi = max(maxi, max(pre, suff));
        }
        return maxi;
    }
};