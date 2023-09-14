class Solution {
public:
    void mergesort(vector<int>& nums,int low,int mid,int high)
    {
        int size=high-low+1;
        vector<int> temp(size,0);
        int left=low,right=mid+1,k=0;
        while(left<=mid && right<=high)
        {
            if(nums[left]<nums[right])
                temp[k++]=nums[left++];
            else
                temp[k++]=nums[right++];
        }
        while(left<=mid)
            temp[k++]=nums[left++];
        while(right<=high)
            temp[k++]=nums[right++];
        
        k=0;
        for(int i=low;i<=high;i++)
        {
            nums[i]=temp[k++];
        }
    }
    void merge(vector<int>& nums,int low,int high)
    {
        if(low>=high)
            return ;
        int mid=(low+high)/2;
        merge(nums,low,mid);
        merge(nums,mid+1,high);
        mergesort(nums,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        merge(nums,0,nums.size()-1);
        return nums;
        
    }
};