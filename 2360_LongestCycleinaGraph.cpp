class Solution {
public:
    int ans = -1;
    void dfs(vector<int> &edges, vector<bool> &vis,unordered_map<int,int> &dist,  int currNode){
        vis[currNode]=true;
        int neighbor  = edges[currNode];
        if (neighbor != -1 && !vis[neighbor]){
            dist[neighbor] = dist[currNode]+1;
            dfs(edges,vis,dist,neighbor);
        }
        else if (neighbor != -1 && dist.find(neighbor) != dist.end()){
            ans  = max(ans, dist[currNode] - dist[neighbor]+ 1);
        }
        
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n,false);
        for (int i =0 ; i<n ; i++){
            if (!vis[i]){
                unordered_map<int, int> dist;
                dist[i] = 1;
                dfs(edges,vis , dist, i);
            }
        }
        return ans;
    }
};