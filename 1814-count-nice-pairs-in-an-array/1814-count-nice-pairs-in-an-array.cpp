class Solution {
public:
      int rev(int n) {
    int res = 0;
    for (; n > 0; n /= 10)
        res = res * 10 + n % 10;
    return res;
}
    int countNicePairs(vector<int>& nums) {
     map<int,int> mp;
    long long ans=0;
        for(auto i:nums)
        {
           ans=(ans+mp[i-(rev(i))]++)%1000000007;
        }
        
        return ans;
    }
};