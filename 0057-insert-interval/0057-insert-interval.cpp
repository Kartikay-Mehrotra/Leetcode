class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int j=0;
        vector<vector<int>> ans;
        int n=intervals.size();
        while(j<n && intervals[j][1]<newInterval[0])
                ans.push_back(intervals[j++]);
        
        while (j < n && intervals[j][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[j][0]);
            newInterval[1] = max(newInterval[1], intervals[j][1]);
            j++;
        }
        
        ans.push_back(newInterval);
        while(j<n)
            ans.push_back(intervals[j++]);
        return ans;
    }
};