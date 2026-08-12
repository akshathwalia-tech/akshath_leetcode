class Solution {
public:
    bool dfs(int node,int col,vector<int> &color, vector<int> adj[]){
        color[node] = col;
        for(int neighbour : adj[node]){
            if(color[neighbour]==-1){
                if(!dfs(neighbour,!col,color,adj)) return false;
            }
            else if(color[neighbour] == col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> adj[v];
        for(int i = 0;i<v;i++){
            for(int j = 0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> color(v,-1);
         for(int i = 0;i<v;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,adj)==false) return false;
            }
         }
         return true;
    }
};