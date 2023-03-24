//bfs
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
         vector<vector<pair<int,bool>>> adj(n);
        for (vector<int> &connection : connections){
            adj[connection[0]].push_back({connection[1],true});
            adj[connection[1]].push_back({connection[0],false});
        }
        vector<bool> vis(n,false);
        vis[0] = true;
        queue<int> q;
        q.push(0);
        int ans =0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for (auto &child : adj[curr]){
                if (!vis[child.first]){
                    ans += child.second;
                    vis[child.first] = true;
                    q.push(child.first);
                }
            }
        }
        return ans;
    }
};

//dfs
class Solution {
public:
    void dfs(vector<vector<pair<int,bool>>> &adj, vector<bool> &vis, int &ans , int curr){
        vis[curr] = true;
        for (auto &child: adj[curr]){
            if (!vis[child.first]){
                ans+=child.second;
                dfs(adj,vis,ans,child.first);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,bool>>> adj(n);
        for (vector<int> &connection : connections){
            adj[connection[0]].push_back({connection[1],true});
            adj[connection[1]].push_back({connection[0],false});
        }
        vector<bool> vis(n,false);
        int ans =0;
        dfs(adj, vis, ans, 0);
        return ans;
    }
};