class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         int i=0;
       int curr;
       int n=nums.size();
       while(i<n)
       {
           curr=nums[i]-1;
           if(nums[i]!=i+1)
           {
           if(nums[i]<n && nums[i]!=nums[curr])
           swap(nums[i],nums[curr]);
           else
           return nums[i];
           }
           else
           i++;
       }
       return -1;
    }
    
};