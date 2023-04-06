// 1254_NumberofClosedIslands
class Solution {
public:
    int rows , cols;
    void dfs(vector<vector<int>>& grid, bool &isClosedIsland, int currRow, int currCol){
        vector<pair<int,int>> dir = {{1,0} ,{0,1}, {-1, 0 }, {0, -1}};
        for (auto &d : dir){
            int row = currRow + d.first;
            int col = currCol + d.second;

            if (row >= 0 && row<rows && col>=0 && col<cols && grid[row][col] ==0 ){
                if (row == 0 || col == 0 || row == rows -1 || col == cols-1 )
                    isClosedIsland = false;
                grid[row][col] = 1;
                dfs(grid, isClosedIsland, row, col);
            }
        }

    }
    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int ans = 0;
        for (int i = 1 ; i<rows-1 ; i++ ){
            for (int j =1; j<cols-1 ; j++){
                if(grid[i][j] == 0){
                    bool isClosedIsland = true;
                    dfs(grid,isClosedIsland, i, j);
                    if (isClosedIsland) ans++;
                }
            }
        }
        return ans;
    }
};