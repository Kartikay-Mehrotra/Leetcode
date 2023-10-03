class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans=0;
        map<double,int> m;
        for(auto i:rectangles)
        {
            double r=(double)i[0]/(double)i[1];
            m[r]++;
        }
        for(auto i:m)
        {
      
            long long t=0;
            if(i.second>1)
            t=(long long)(i.second)*(i.second -1)/2;
            ans+=t;
        }
        return ans;
    }
};