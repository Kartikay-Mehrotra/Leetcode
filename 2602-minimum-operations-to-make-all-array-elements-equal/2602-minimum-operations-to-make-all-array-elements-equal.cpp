class Solution {
public:
    int f(vector<int> &nums,int temp)
    {
        int n = nums.size();
        int ans=-1;
        int l=0,h=n-1;
        while(l<=h)
        {
            int m = (l+h)/2;
            if(nums[m]>=temp)
            {
                ans=m;
                h=m-1;
            }
            else
            l=m+1;
        }
        return ans;
    }

    vector<long long> minOperations(vector<int>& nums, vector<int>& q) {
        int n = nums.size();
        int m = q.size();
        vector<long long> v;
        sort(nums.begin(),nums.end());
        vector<long long> p(n+1, 0);
        for(int i=0;i<n;i++)
        {
            p[i+1] = p[i]+nums[i];
        }
        for(auto it:q)
        {
            if(it<nums[0] || it>nums[n-1])
            {
                v.push_back(abs(p[n]-(it*1LL*n)));
                continue;
            }
            int temp = f(nums,it);
            cout<<temp;
            long long sum = abs(p[temp]-(temp*1LL*it))+abs(p[n]-p[temp]-((n-temp)*1LL*it));
            v.push_back(sum);
        }
        return v;
    }
};