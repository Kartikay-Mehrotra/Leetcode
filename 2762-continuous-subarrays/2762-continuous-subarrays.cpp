class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
     
        long long ans=0;
        multiset<int> s;
        int start=0;
        int end=0;
        int n=nums.size();
        
        while(end<n)
        {
            s.insert(nums[end]);
            while(s.size() && (*--s.end()-*s.begin())>2)
            {
                s.erase(s.find(nums[start]));
                start++;
            }
            ans+=end-start;
            end++;
        }
        
        
        return ans+n;
    }
};