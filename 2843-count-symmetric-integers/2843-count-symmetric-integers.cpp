class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++)
        {
            string s=to_string(i);
            int t=0;
            int n=s.size();
            if(n&1)
            continue;
            for(int j=0;j<n/2;j++)t+=(s[j]-s[n-j-1]);
            if(t==0)
            ans++;
        }
        return ans;
    }
};