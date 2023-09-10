class Solution {
public:
    int n,m;
    int f(int ind, vector<vector<int>> &v0, vector<vector<int>> &v1, vector<vector<int>> &grid){
        if(ind == v0.size()) return 0;
        
        int ans = INT_MAX;
        for(int i = 0; i < v1.size(); ++i){
            int r = v1[i][0], c = v1[i][1];
            if(grid[r][c] > 1){
                grid[r][c]--;
                ans = min(ans, abs(r-v0[ind][0]) + abs(c-v0[ind][1]) + f(ind+1, v0, v1, grid));
                grid[r][c]++;
            } 
        }
        return ans;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> v0, v1;
        for(int i = 0; i < n; ++i){
            for(int j =0; j < m; ++j){
                if(grid[i][j] == 0) v0.push_back({i,j});
                if(grid[i][j] > 1) v1.push_back({i,j});
            }
        }
        return f(0,v0,v1,grid);
    }
};