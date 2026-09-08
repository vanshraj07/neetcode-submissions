class Solution {
private:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>&vis){
        int m=grid.size();
        int n=grid[0].size();
        if(row>=m || col>=n) return;
        vis[row][col]=1;
        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,-1,0,1};
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1' && !vis[nr][nc]){
                dfs(nr,nc,grid,vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return ans;
    }
};
