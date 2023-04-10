//1857_LargestColorValueinaDirectedGraph
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
       int n = colors.size();
       vector<vector<int>> adj(n);
       vector<int> incoming(n);
       for(auto &edge : edges){
         adj[edge[0]].push_back(edge[1]);
         incoming[edge[1]]++;
       }
       vector<vector<int>> colorCount(n, vector<int>(26));
       queue<int> q;
       for (int i =0 ; i<n;i++){
         if (incoming[i] == 0) q.push(i);
       }
       int ans =0 , totalProssed = 0 ;
       while(!q.empty()){
        int currQueSize = q.size();
        while(currQueSize--){
          int currNode = q.front();
          q.pop();
          totalProssed++;
          colorCount[currNode][colors[currNode] -  'a']++;
          ans = max(ans, colorCount[currNode][colors[currNode] -  'a']);
          for (int &child : adj[currNode]){
            incoming[child]--;
            if (incoming[child] == 0 ) q.push(child);

            for (int i = 0 ; i<26; i++ ){
              colorCount[child][i] = max(colorCount[child][i] , colorCount[currNode][i]);
            }
          }
        }
      }
      return totalProssed!=n?-1:ans;
    }
};
