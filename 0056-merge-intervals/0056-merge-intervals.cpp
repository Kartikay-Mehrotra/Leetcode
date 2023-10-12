class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> a;
        sort(intervals.begin(),intervals.end());
        for(auto i:intervals)
        {
            if(a.empty() || a.back()[1]<i[0])
                a.push_back(i);
            else 
                a.back()[1]=max({a.back()[1],i[1]});
        }
        return a;
        
    }
};