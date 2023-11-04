class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> fp(n,0);
        fp[0]=height[0];
        for(int i=1;i<n;i++)
        {
            fp[i]=max(fp[i-1],height[i]);
        }
        vector<int> bp(n,0);
        bp[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            bp[i]=max(bp[i+1],height[i]);
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=min(fp[i],bp[i])-height[i];
        }
        return ans;
    }
};