//O(n^2)
class Solution {
public:
    TreeNode* buildTreeRecursively(vector<int> &inorder ,int sti , int endi, vector<int> &postorder, int stp, int endp ){
        if (sti > endi || stp > endp ) return NULL;

        TreeNode* root = new TreeNode(postorder[endp]);

        int currSti = sti; 
        while (inorder[currSti] != root->val ) currSti++;

        root->left = buildTreeRecursively(inorder, sti ,currSti -1 , postorder , stp , stp + currSti -1-sti );
        root->right = buildTreeRecursively(inorder,currSti +1, endi , postorder, stp + currSti - sti , endp -1 );
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int totalNodesInTree = inorder.size();
        return buildTreeRecursively(inorder, 0 , totalNodesInTree-1, postorder , 0 , totalNodesInTree-1);
    }
};

//O(n)
class Solution {
public:
    unordered_map<int, int> inorderMap;
    TreeNode* buildTreeRecursively(vector<int> &inorder ,int sti , int endi, vector<int> &postorder, int stp, int endp ){
        if (sti > endi || stp > endp ) return NULL;

        TreeNode* root = new TreeNode(postorder[endp]);

        int currSti = inorderMap[root->val];

        root->left = buildTreeRecursively(inorder, sti ,currSti -1 , postorder , stp , stp + currSti -1-sti );
        root->right = buildTreeRecursively(inorder,currSti +1, endi , postorder, stp + currSti - sti , endp -1 );
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int totalNodesInTree = inorder.size();
        for (int i = 0 ; i<totalNodesInTree ; i++ ) {
            inorderMap[inorder[i]]  = i;
        }
        return buildTreeRecursively(inorder, 0 , totalNodesInTree-1, postorder , 0 , totalNodesInTree-1);
    }
};