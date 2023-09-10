class Solution {
public:
    static bool comp(const string &a,const string &b)
    {
        if(a.size()==b.size())
        {
            int i=0;
            for(int i=0;i<a.size();i++)
            {
                if(a[i]==b[i])
                    continue;
                else
                {
                    return a[i]<b[i];
                }
            }
        }
        return  a.size()<b.size();
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),comp);
        return nums[nums.size()-k];
    }
};