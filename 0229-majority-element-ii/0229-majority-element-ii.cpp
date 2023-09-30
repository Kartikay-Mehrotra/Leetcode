class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int e1=INT_MIN;
        int e2=INT_MIN;
        int c1=0;
        int c2=0;
        
        for(auto i:nums)
        {
            if(e2!=i && c1==0)
            {
                e1=i;
                c1=1;
            }
            else if(e1!=i && c2==0)
            {
                e2=i;
                c2=1;
            }
            else if(i==e1)
            {
                c1++;
            }
            else if(i==e2)
            {
                c2++;
            }
            else
            {
                c2--;
                c1--;
            }
        }
        int ca=0,cb=0;
        for(auto i:nums)
        {
            if(i==e1)
                ca++;
            else if(i==e2)
                cb++;
        }
        vector<int> ans;
        if(ca>nums.size()/3)
            ans.push_back(e1);
        if(cb>nums.size()/3)
            ans.push_back(e2);
        
        return ans;
        
    }
};