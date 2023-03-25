//DFS
class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<bool> &vis, long long &nodesInCurrGraph,int curr){
        vis[curr]=true;
        nodesInCurrGraph++;
        for (int &child : adj[curr]){
            if (!vis[child]){
                dfs(adj, vis,nodesInCurrGraph,child);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int> &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);
        long long ans = 0;
        int reaminingNodes = n;
        for (int i = 0 ; i<n;i++ ){
            if (!vis[i]){
                long long nodesInCurrGraph = 0;
                dfs(adj, vis,nodesInCurrGraph,i);
                ans+= nodesInCurrGraph * (reaminingNodes - nodesInCurrGraph);
                reaminingNodes -= nodesInCurrGraph;
            }
            
        }
        return ans;
    }
};

//UnionFind
class UnionFind {
private:
    vector<int> root;
    vector<int> rank;
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }
    
    void unionSet(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) {
                root[rooty] = rootx;
            } else if (rank[rootx] < rank[rooty]) {
                root[rootx] = rooty;
            } else {
                root[rooty] = rootx;
                rank[rootx] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        UnionFind dsu(n);
        for (vector<int> &edge : edges ){
            dsu.unionSet(edge[0], edge[1]);
        }
        
        unordered_map<int, int> graphSize;
        for (int i = 0 ;i<n ;i++ ){
            graphSize[dsu.find(i)]++;   
        }

        long long ans =0;
        long long remainingNodes =n;
        for (auto &[root, nodesInCurrGraph] : graphSize){
            ans += nodesInCurrGraph * (remainingNodes - nodesInCurrGraph);
            remainingNodes -= nodesInCurrGraph;
        }
        return ans;
    }
};