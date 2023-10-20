class Solution {
public:
bool isp(vector<int>& nums,int mid,int threshold)
{
    int sum=0;
    for(auto i:nums)
    {
        sum+=ceil((double)i/(double)mid);
    }
    return sum<=threshold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
// if(nums.size()>threshold)
// return -1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isp(nums,mid,threshold))
            {
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return low;
    }
};