class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        int r = 0;
        for (int i = 0 ; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    bool can = false;
                    for (int k = 0; !can && k < n; ++k) {
                        can = (k != j && grid[i][k]);
                    }
                    for (int k = 0; !can && k < m; ++k) {
                        can = (k != i && grid[k][j]);
                    }
                    r += can;
                    
                }
            }
        }
        return r;
    }
};