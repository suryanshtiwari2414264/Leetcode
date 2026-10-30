class Solution {
public:
    int bfs(int src,vector<int>adj_list[],vector<bool>& visited){
        int count =1;
        queue<int> q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v: adj_list[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                    count++;
                }
            }
        }
        return count;

    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<bool>visited(n,false);
        vector<int> adj_list[n];
        for(int i = 0; i<edges.size();i++){
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }
        for(auto a: restricted){
            visited[a]=true;
        }
        int count = bfs(0,adj_list,visited);

        return count;

    }

};