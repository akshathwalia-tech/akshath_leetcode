class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto& it : prerequisites){
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto& nei : adj[node]){
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                }
            }
        }
       if (ans.size() == numCourses) {
            return ans;
        }
        return {};
    }
};