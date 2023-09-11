class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        int s=0;
        m[0]=1;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            int l=s-k;
            count+=m[l];
            m[s]++;
        }
        return count;
        
    }
};