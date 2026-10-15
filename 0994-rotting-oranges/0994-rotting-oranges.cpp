// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         queue<pair<int, int>> q;
//         int fresh = 0;
//         int time = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (grid[i][j] == 2)
//                     q.push({i, j});
//                 else if (grid[i][j] == 1)
//                     fresh++;
//             }
//         }
//         int dr[] = {-1, 1, 0, 0};
//         int dc[] = {0, 0, -1, 1};
//         while (!q.empty() && fresh > 0) {
//             int size = q.size();
//             for (int i = 0; i < size; i++) {
//                 auto [r, c] = q.front();
//                 q.pop();
//                 for (int d = 0; d < 4; d++) {
//                     int nr = r + dr[d];
//                     int nc = c + dc[d];
//                     if (nr >= 0 && nr < n &&
//                         nc >= 0 && nc < m &&
//                         grid[nr][nc] == 1) {
//                         grid[nr][nc] = 2;
//                         fresh--;
//                         q.push({nr, nc});
//                     }
//                 }
//             }
//             time++;
//         }
//         if (fresh > 0)
//             return -1;
//         return time;
//     }
// };
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        int fresh_count = 0;
        int time = -1;
        queue<pair<int,int>> q;
           for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh_count++;
            }
        }
        q.push({-1,-1});
        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            if(r==-1 && c==-1){
                time++;
                if(!q.empty()){
                    q.push({-1,-1});
                }
            }
            else
            {
            // Deal with all valid neighbour
    
                if(r-1>=0 && grid[r-1][c] ==1){
                    grid[r-1][c]=2;
                    fresh_count --;
                    q.push({r-1,c});
                }
                if(r+1<m && grid[r+1][c] ==1){
                    grid[r+1][c]=2;
                    fresh_count --;
                    q.push({r+1,c});
                }
                if(c-1>=0 && grid[r][c-1] ==1){
                    grid[r][c-1]=2;
                    fresh_count --;
                    q.push({r,c-1});
                }
                if(c+1<n && grid[r][c+1] ==1){
                    grid[r][c+1]=2;
                    fresh_count --;
                    q.push({r,c+1});
                }
            }
        }
        return fresh_count == 0 ? time : -1;

    }
};