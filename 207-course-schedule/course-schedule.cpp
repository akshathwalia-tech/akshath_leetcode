class Solution {
public:
    bool dfs(int node,vector<int>& visited,vector<vector<int>>& adj){
        visited[node] = 1;
        for(int neighbour : adj[node]){
            if(visited[neighbour] == 0){
                if(dfs(neighbour,visited,adj)){
                    return true;
                }
                }
                else if(visited[neighbour]==1){
                return true;
            }
        }
        visited[node] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& req : prerequisites) {
            adj[req[1]].push_back(req[0]);
        }
        vector<int> visited(numCourses,0);
        for(int i = 0; i<numCourses;i++){
        if(!visited[i]){
            if(dfs(i,visited,adj)){
                return false;
            }
        }
        }
        return true;
    }
};