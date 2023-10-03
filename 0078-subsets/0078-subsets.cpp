class Solution {
public:
    void solve(int indx,vector<int>& mid,vector<int>& nums,vector<vector<int>>& ans)
    {
        if(indx==nums.size())
        {
            ans.push_back(mid);
            return ;
        }
        mid.push_back(nums[indx]);
        solve(indx+1,mid,nums,ans);
        mid.pop_back();
        
        solve(indx+1,mid,nums,ans);
    
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> mid;
        solve(0,mid,nums,ans);
        return ans;
    }
};