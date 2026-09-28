class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<bool> visited(n,false);
        int count =0;
        for(int i = 0; i<n;i++){
            if(visited[i]==false){
                bfs(isConnected,i,visited);
                count++;
            }
        }
        return count;
    }
    void bfs( vector<vector<int>>&isConnected,int src,vector<bool>&visited){
        queue<int>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            // Push all unvisited neighbour
            for (int v = 0; v < isConnected.size(); v++){
                if(visited[v]==false && isConnected[u][v]==1){
                q.push(v);
                visited[v]=true;
                }
            }
        }
    }
};