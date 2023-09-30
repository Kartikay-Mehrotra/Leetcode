class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        sort(intervals.begin(),intervals.end());
        
        for(auto i:intervals)
        {
            if(output.size()==0 || output.back()[1]<i[0])
            {
                output.push_back(i);
                
            }
            else
                output.back()[1]=max(output.back()[1],i[1]);
                
        }
        return output;
    }
};