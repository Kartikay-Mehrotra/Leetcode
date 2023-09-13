class Solution {
public:
int sum;
    void DFS(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
        if(i<0||j>=m||j<0||i>=n||grid[i][j]==0)
        return ;
        sum++;
        grid[i][j]=0;
       DFS(grid,i+1,j,n,m);
        DFS(grid,i-1,j,n,m);
      DFS(grid,i,j+1,n,m);
        DFS(grid,i,j-1,n,m);
       
        //return 1+max(max(op1,op2),max(op3,op4));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int maxi=INT_MIN;
     
       int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                sum=0;
                if(grid[i][j]==1)
                 DFS(grid,i,j,n,m);
                if(sum>maxi)
                maxi=sum;
            }
        }
        return maxi;
    }
};