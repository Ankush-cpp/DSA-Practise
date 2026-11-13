#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {

        int m = grid.size();
        int n = grid[0].size();

        if (r < 0 || c < 0 || r >= m || c >= n ||
            grid[r][c] == '0' || visited[r][c]) {
            return;
        }

        visited[r][c] = true;

        dfs(r + 1, c, grid, visited);
        dfs(r - 1, c, grid, visited);
        dfs(r, c + 1, grid, visited);
        dfs(r, c - 1, grid, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    cout << sol.numIslands(grid) << endl;

    return 0;
}