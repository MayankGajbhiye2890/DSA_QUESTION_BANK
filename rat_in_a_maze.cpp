#include <bits/stdc++.h> 
using namespace std;

bool issafe(int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n) {
    if (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && arr[x][y] == 1) {
        return true;
    }
    return false;
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path) {
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = true;

    // down
    if (issafe(x + 1, y, visited, arr, n)) {
        solve(x + 1, y, arr, n, ans, visited, path + 'D');
    }
    // left
    if (issafe(x, y - 1, visited, arr, n)) {
        solve(x, y - 1, arr, n, ans, visited, path + 'L');
    }
    // right
    if (issafe(x, y + 1, visited, arr, n)) {
        solve(x, y + 1, arr, n, ans, visited, path + 'R');
    }
    // up
    if (issafe(x - 1, y, visited, arr, n)) {
        solve(x - 1, y, arr, n, ans, visited, path + 'U');
    }

    visited[x][y] = false; 
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    vector<string> ans; 
    string path = ""; //path ko ans me
    if(arr[0][0]==0){
        return ans;
    }
    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}





//gfg question if path exists or not
class Solution {
public:
    // Function to find whether a path exists from the source to destination.
    bool issafe(int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &grid, int n) {
        // Check boundaries and ensure cell is not visited and is either blank (3) or destination (2)
        if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && (grid[x][y] == 3 || grid[x][y] == 2)) {
            return true;
        }
        return false;
    }

    bool solve(int x, int y, vector<vector<int>> &grid, int n, vector<vector<bool>> &visited) {
        // If destination is reached, return true
        if (grid[x][y] == 2) return true;

        visited[x][y] = true;

        // Check all four directions
        // Down
        if (issafe(x + 1, y, visited, grid, n) && solve(x + 1, y, grid, n, visited)) return true;
        // Left
        if (issafe(x, y - 1, visited, grid, n) && solve(x, y - 1, grid, n, visited)) return true;
        // Right
        if (issafe(x, y + 1, visited, grid, n) && solve(x, y + 1, grid, n, visited)) return true;
        // Up
        if (issafe(x - 1, y, visited, grid, n) && solve(x - 1, y, grid, n, visited)) return true;

        // Unmark the cell as visited if no path found (for backtracking)
        visited[x][y] = false;
        return false;
    }

    bool is_Possible(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int srcX = -1, srcY = -1;

        // Locate source cell (1)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    srcX = i;
                    srcY = j;
                    break;
                }
            }
            if (srcX != -1) break;
        }

        // If source not found, return false
        if (srcX == -1 || srcY == -1) return false;

        // Start DFS or recursive backtracking from the source
        return solve(srcX, srcY, grid, n, visited);
    }
};
