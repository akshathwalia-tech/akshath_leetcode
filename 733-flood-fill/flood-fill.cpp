class Solution {
public:
    void dfs(vector<vector<int>>& image,int r,int c,int initialcolor,int color,int n,int m){
        if(r<0 || c<0 || r>=n || c>=m || image[r][c] != initialcolor)
        {
            return;
        }
        image[r][c] = color;

        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        for(int i = 0;i<4;i++){
            dfs(image,r + dx[i],c + dy[i],initialcolor,color,n,m);
        } 
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialcolor = image[sr][sc];

        if(initialcolor == color){
            return image;
        }
        int n = image.size();
        int m = image[0].size();

        dfs(image,sr,sc,initialcolor,color,n,m);

        return image;
    }
};