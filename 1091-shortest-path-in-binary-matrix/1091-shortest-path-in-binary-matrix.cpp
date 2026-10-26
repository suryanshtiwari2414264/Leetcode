// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();
//         //EDGE CASES
//         if(n==0 || grid[0][0] ==1 || grid[n-1][n-1]==1)
//             return -1;
//         if(n==1)
//             return 1;
//         vector<pair<int,int>> dirs={
//             {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}
//         };
//         //Setup BFS
//         queue<array<int,3>>q;
//         q.push({0,0,1});//PUSH SRC
//         grid[0][0]=1;//VISIT
//         while(!q.empty()){
//             auto [r,c,d]= q.front();
//             q.pop();
//             if(r== n-1 && c==n-1)
//                 return d;
//             //EXPLORE THE NEIGHBOURS
//             for(auto [x,y] : dirs){
//                 int rn = r + x;
//                 int cn = c + y;
//                 if(rn>= 0 && rn<n && cn>=0 && cn<n && grid[rn][cn]==0){
//                     grid[rn][cn]=1;//mark it visited
//                     q.push({rn,cn,d+1});//push in queue

//                 }
//             }
//         }
//         return -1;
//     }
// };

//DIJKSTRA'S ALGORITHM

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        int n= grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0]=1;
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
        pq.push({1,{0,0}});
        vector<pair<int,int>> dirs={
             {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}
         };
        while(!pq.empty()){
            auto[d,pos]=pq.top();
            pq.pop();
            int x = pos.first;
            int y = pos.second;

            if(d>dist[x][y]){
                continue;
            }
            if(x==n-1 && y == n-1)
                return d;
            for(auto &edge: dirs){
                int rn = x + edge.first;
                int cn = y + edge.second;
                if(rn>= 0 && rn<n && cn>=0 && cn<n && grid[rn][cn]==0){
                    grid[rn][cn]=1;//mark it visited
                    pq.push({d+1,{rn,cn}});//push in queue
                }
            }
        }
        return -1;
    }
};