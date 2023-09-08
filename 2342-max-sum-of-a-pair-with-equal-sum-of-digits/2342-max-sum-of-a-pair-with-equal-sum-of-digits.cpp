class Solution {
public:
    long long sum(int num)
    {
        long long sum=0;
        while(num>0)
        {
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<long long,multiset<int,greater<int>>> m;
        for(int i=0;i<nums.size();i++)
        {
            long long  s=sum(nums[i]);
            m[s].insert(nums[i]);
        }
        int ans=INT_MIN;
        for(auto i:m)
        {
            if(i.second.size()==1)
                continue;
            int a=*i.second.begin();
            i.second.erase(i.second.begin());
            int b=*i.second.begin();
            if(a+b >ans)
                ans=a+b;
        }
        return ans!=INT_MIN?ans:-1;
        
    }
};