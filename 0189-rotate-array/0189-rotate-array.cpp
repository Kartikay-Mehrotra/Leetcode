class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        int a=k%n;
        reverse(nums.begin()+n-a,nums.end());
        reverse(nums.begin(),nums.end()-a);
        reverse(nums.begin(),nums.end());
    }
};