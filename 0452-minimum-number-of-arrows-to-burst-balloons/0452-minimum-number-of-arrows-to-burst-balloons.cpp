class Solution {
public:
    bool static comp(const vector<int>& a,const vector<int>& b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=1;
        sort(points.begin(),points.end(),comp);
        int a=points[0][1];
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]>a)
            {
                a=points[i][1];
                ans++;
            }
        }
        return ans;
    }
};