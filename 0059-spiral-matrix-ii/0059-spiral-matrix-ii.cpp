class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int fill=1;
        vector<vector<int>> ans(n,vector<int>(n,1));
        int top=0;
        int left=0;
        int right=n-1;
        int bottom=n-1;
        
        while(left<=right && top<=bottom)
        {
            for(int i=left;i<=right;i++)
            {
                ans[top][i]=fill;
                fill++;
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                ans[i][right]=fill;
                fill++;
            }
            right--;
            if(top<=bottom)
            {
                for(int i=right;i>=left;i--)
                {
                    ans[bottom][i]=fill;
                    fill++;
                }
                bottom--;
            }
            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    ans[i][left]=fill;
                    fill++;
                }
                left++;
            }
        }
        return ans;
    }
};