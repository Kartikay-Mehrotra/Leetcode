class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> output(n+1);
        for(int i=0;i<n+1;i++)
        {
            output[i].resize(i+1,1);
            for(int j=1;j<i;j++)
            {
                output[i][j]=output[i-1][j-1]+output[i-1][j];
            }
        }
        return output[n];
    }
};