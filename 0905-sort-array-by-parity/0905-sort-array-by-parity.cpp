class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd,eve;
        for(auto i:nums)
            if(i&1)
                odd.push_back(i);
            else
                eve.push_back(i);
        
        eve.insert(eve.end(),odd.begin(),odd.end());
        return eve;
    }
};