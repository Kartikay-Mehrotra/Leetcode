class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c1=0;
        int c2=0;
        int e1=INT_MIN;
        int e2=INT_MIN;
        for(auto i:nums)
        {
            if(e2!=i && c1==0)
            {
                e1=i;
                c1=1;
            }
            if(e1!=i && c2==0)
            {
                e2=i;
                c2=1;
            }
            if(e1==i)
                c1++;
            else if(e2==i)
                c2++;
            else
                c1--,c2--;
        }
        c1=0,c2=0;
        for(auto i:nums)
        {
            if(e1==i)
                c1++;
            if(e2==i)
                c2++;
        }
        if(c1>nums.size()/2)
            return e1;
        else if(c2>nums.size()/2)
            return e2;
        else
            return -1;
    }
};