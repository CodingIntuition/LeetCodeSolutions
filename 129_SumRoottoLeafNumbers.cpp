    // DFS 
    class Solution {
    public:
        void dfs(TreeNode* root, int currNumber , int &ans){
            if (root == NULL) return;

            currNumber = currNumber*10 + root->val;

            if (root->left==NULL && root->right==NULL) {
                ans += currNumber;
            }
            
            dfs(root->left,currNumber, ans );
            dfs(root->right, currNumber , ans);
        }
        int sumNumbers(TreeNode* root) {
            int ans = 0;
            dfs(root,0 , ans);
            return ans;
        }
    };

    //BFS
    class Solution {
    public:
        int sumNumbers(TreeNode* root) {
            queue<pair<TreeNode*, int> > bfsQueue;
            bfsQueue.push({root, root->val});
            int ans = 0;
            while (!bfsQueue.empty()){
                auto curr =  bfsQueue.front();
                bfsQueue.pop();

                if (curr.first->left == NULL && curr.first->right == NULL ) ans +=  curr.second;

                if (curr.first->left){
                    bfsQueue.push({curr.first->left, curr.second*10 +  curr.first->left->val});
                }
                if (curr.first->right){
                    bfsQueue.push({curr.first->right, curr.second*10 + curr.first->right->val});
                }
            }
            return ans;
        }
    };