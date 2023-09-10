class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> forw(n);
        int maxi = INT_MIN;
        forw[0] = height[0];
        
 
        for(int i=1; i<n; i++){
            forw[i] = max(forw[i-1], height[i]);
        }
        
        vector<int> back(n);
       
        back[n-1] = height[n-1];
        
        for(int i = n-2; i>=0; i--){
            back[i] = max(back[i+1], height[i]);
        }
        
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += min(forw[i] ,back[i]) - height[i];
        }
        
        return sum;
    }
};