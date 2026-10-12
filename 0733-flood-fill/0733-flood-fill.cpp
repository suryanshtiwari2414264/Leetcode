class Solution {
private:
    // void dfs(vector<vector<int>>& image,int r,int c,int old_color,int new_color ){
    //     image[r][c] = new_color;
    //     if(r-1>=0 && image[r-1][c]==old_color)
    //         dfs(image,r-1,c,old_color,new_color);
    //     if(r+1<image.size() && image[r+1][c]==old_color)
    //         dfs(image,r+1,c,old_color,new_color);
    //     if(c-1>=0 && image[r][c-1]==old_color)
    //         dfs(image,r,c-1,old_color,new_color);
    //     if(c+1<image[0].size() && image[r][c+1]==old_color)
    //         dfs(image,r,c+1,old_color,new_color);
    // }
    void bfs(vector<vector<int>>& image,int r,int c,int new_color){
        int old_color = image[r][c];
        image[r][c] = new_color;
        queue<pair<int,int>>q;
        q.push({r,c});//source is initialised
        while(!q.empty()){
            pair<int,int> src=q.front();
            q.pop();
            int r = src.first;
            int c = src.second;
            if(r-1>=0 && image[r-1][c]==old_color){
                image[r-1][c]= new_color;
                q.push({r-1,c});
            }
            if(r+1<image.size() && image[r+1][c]==old_color){
                image[r+1][c]= new_color;
                q.push({r+1,c});
            }
            if(c-1>=0 && image[r][c-1]==old_color){
                image[r][c-1]= new_color;
                q.push({r,c-1});
            }
            if(c+1<image[0].size() && image[r][c+1]==old_color){
                image[r][c+1]= new_color;
                q.push({r,c+1});
            }
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // int old_color = image[sr][sc];
        // if(old_color != color){
        //     dfs(image,sr,sc,old_color,color);
        // }
        if(image[sr][sc] == color){
            return image;
        }
        bfs(image,sr,sc,color);
            return image;


    }
};