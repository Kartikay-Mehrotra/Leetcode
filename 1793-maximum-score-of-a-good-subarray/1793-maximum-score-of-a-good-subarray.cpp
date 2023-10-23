class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left=k-1,right=k+1;
        int ans=nums[k];
        int cur=nums[k];
        while(left>=0 || right<nums.size()){
            // cout<<left<<" "<<right<<endl;
            if((left>=0?nums[left]:0) < (right<nums.size()?nums[right]:0)){
                // cout<<"hii"<<endl;
                cur=min(cur,nums[right]);
                ans=max(ans,cur*(right-left));
                right++;
            }
            else{
                // cout<<"hello"<<endl;
                cur=min(cur,nums[left]);
                ans=max(ans,cur*(right-left));
                left--;
            }
        }
        return ans;
    }
};