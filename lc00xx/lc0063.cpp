//--- Q: 0063. Unique Paths II

//--- method 1: dp iteration
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        obstacleGrid[0][0] = -1;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                if (i && obstacleGrid[i-1][j] < 0) {
                    obstacleGrid[i][j] += obstacleGrid[i-1][j];
                }
                if (j && obstacleGrid[i][j-1] < 0) {
                    obstacleGrid[i][j] += obstacleGrid[i][j-1];
                }
            }
        }
        return obstacleGrid[row-1][col-1] < 0 ? abs(obstacleGrid[row-1][col-1]) : 0;
    }
};

//--- method 2: dfs recursion with memo
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<int>> visit(row, vector<int>(col, -1));
        return dfs(row-1, col-1, obstacleGrid, visit);
    }
    int dfs(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& visit) {
        if (visit[i][j] != -1) {
            return visit[i][j];
        }
        if (obstacleGrid[i][j] == 1) {
            return visit[i][j] = 0;
        }
        if (!i && !j) {
            return visit[i][j] = 1;
        }
        int v = 0;
        if (i) {
            v += dfs(i-1, j, obstacleGrid, visit);
        }
        if (j) {
            v += dfs(i, j-1, obstacleGrid, visit);
        }
        return visit[i][j] = v;
    }
};