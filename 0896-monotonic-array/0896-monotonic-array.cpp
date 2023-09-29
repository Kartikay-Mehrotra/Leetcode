class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> t1,t2;
        t1=nums;
        t2=nums;
        sort(t1.begin(),t1.end());
        sort(t2.begin(),t2.end(),greater<int>());
        if(t1==nums || t2==nums)
            return true;
        
        
        return false;
    }
};