//BFS 
class Solution {
public:
    
    bool isCompleteTree(TreeNode* root) {
        if (root == NULL ) return true;

        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);

        bool isNullNodeFound = false;

        while (!bfsQueue.empty()){
            int currSize = bfsQueue.size();
            while(currSize--){
                TreeNode* currNode =  bfsQueue.front();
      
                bfsQueue.pop();
                if (currNode == NULL ) {
                    isNullNodeFound = true;
                }
                else {
                    if (isNullNodeFound && currNode )  return false;
                    bfsQueue.push(currNode->left);
                    bfsQueue.push(currNode->right);
                }
                
            }
        }

        return true;
    }
};


//DFS
class Solution {
public:
    int countNodes(TreeNode* root){
        if (root == NULL ) return 0;
        return 1+ countNodes(root->left)  + countNodes(root->right);
    }
    bool dfs(TreeNode* root , int idx , int totalNodes){
        if (root == NULL ) return true;
        if (idx >= totalNodes) return false;
        return dfs(root->left , 2*idx +1, totalNodes) && dfs(root->right ,2*idx + 2, totalNodes );
    }

    bool isCompleteTree(TreeNode* root) {
        
        return dfs(root, 0 ,countNodes(root));
    }
};