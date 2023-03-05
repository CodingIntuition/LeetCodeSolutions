
class Solution {
public:
    int minJumps(vector<int>& arr) {
         
        int arrSize = arr.size();
        if(arrSize == 0 || arrSize == 1) return 0;
        unordered_map<int,vector<int>> neighbors;

        for (int i  = 0; i<arrSize; i++ ){
            neighbors[arr[i]].push_back(i);
        }

        queue<int> bfsQue;
        vector<bool> vis(arrSize , false);
        bfsQue.push(0);
        vis[0] = true;
        int ans = 0;

        while (!bfsQue.empty()){
            int currSize  = bfsQue.size();
            ans++;
            while (currSize--){
                int currIdx = bfsQue.front();
                bfsQue.pop();

                if (currIdx -1 >=0 && !vis[currIdx-1] ) {
                    vis[currIdx -1 ] = true;
                    bfsQue.push(currIdx-1);
                }
                if (currIdx +1 == arrSize-1) {
                    return ans;
                }
                if (currIdx + 1 < arrSize && !vis[currIdx+1]  ){
                    vis[currIdx+1] = true;
                    bfsQue.push(currIdx+1);
                }
                for (int &idx : neighbors[arr[currIdx]]){
                    if (idx == arrSize-1) {
                        return ans;
                    }
                    if (!vis[idx]){
                        bfsQue.push(idx);
                        vis[idx] = true;
                    }
                }
                neighbors[arr[currIdx]] = {};
            }
            
        }
        return ans;
    }
};