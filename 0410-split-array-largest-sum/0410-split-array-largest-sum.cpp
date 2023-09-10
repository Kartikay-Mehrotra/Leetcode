class Solution {
public:
int isp(vector<int>& nums,int cap)
{
    int k=1;
    int s=0;
    for(auto i:nums)
    {
        s+=i;
        if(s>cap)
        {
            k++;
            s=i;
        }
    }
    return k;
}
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isp(nums,mid)>k)
            {
                low=mid+1;
            }
            else
            high=mid-1;
        }
        //cout<<-5%2;
        return low;
    }
};