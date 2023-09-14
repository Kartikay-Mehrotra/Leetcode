class Solution {
public:
    void mergesort(vector<int>& nums,int low,int mid,int high,int &ans)
    {
        int j=mid+1;
        for(int i=low;i<=mid;i++)
        {
            while(j<=high && nums[i]>2*(long long)nums[j])
                j++;
            ans+=(j-(mid+1));
        }
        int size=high-low+1;
        vector<int> temp(size,0);
        int left=low,right=mid+1,k=0;
        while(left<=mid && right<=high)
        {
            if(nums[left]<nums[right])
            {
                temp[k++]=nums[left++];
            }
            else
                temp[k++]=nums[right++];
        }
        while(left<=mid)
            temp[k++]=nums[left++];
        while(right<=high)
            temp[k++]=nums[right++];
        
        int m=0;
        for(int i=low;i<=high;i++)
            nums[i]=temp[m++];
        
    }
    void merge(vector<int>& nums,int low,int high,int & ans)
    {
        if(low>=high)
            return ;
        int mid=(low+high)/2;
        merge(nums,low,mid,ans);
        merge(nums,mid+1,high,ans);
        
        mergesort(nums,low,mid,high,ans);
    }
    int reversePairs(vector<int>& nums) {
        int ans=0;
        merge(nums,0,nums.size()-1,ans);
        return ans;
    }
};