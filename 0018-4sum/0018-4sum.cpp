class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        
        for(int i = 0; i < n - 3; i++) {
            // Skip duplicate values for the first element
            if(i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                for(int j = i + 1; j < n - 2; j++) {
                    // Skip duplicate values for the second element
                    if(j == i + 1 || (j > i + 1 && nums[j] != nums[j - 1])) {
                        long long newTarget = target - static_cast<long long>(nums[i]) - static_cast<long long>(nums[j]);
                        int low = j + 1, high = n - 1;
                        
                        while(low < high) {
                            long long sum = static_cast<long long>(nums[low]) + static_cast<long long>(nums[high]);
                            
                            if(sum < newTarget) {
                                low++;
                            }
                            else if(sum > newTarget) {
                                high--;
                            }
                            else {
                                output.push_back({nums[i], nums[j], nums[low], nums[high]});
                                
                                // Skip duplicate values for the third and fourth elements
                                while(low < high && nums[low] == nums[low + 1]) low++;
                                while(low < high && nums[high] == nums[high - 1]) high--;
                                
                                low++;
                                high--;
                            }
                        }
                    }
                }
            }
        }
        
        return output;
    }
};
