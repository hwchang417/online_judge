/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int rootIndex;
    struct TreeNode* root;
    
    if(preorderSize <= 0 || inorderSize <= 0) return NULL;
    
    root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    if(root == NULL) return NULL;
    
    root->val = preorder[0];
    
    //find root value in inorder array
    for(rootIndex = 0;rootIndex < preorderSize;rootIndex++)
        if(inorder[rootIndex] == root->val){
            break;
        }
    
    //construct left and right subtree with correct index and array size
    root->left = buildTree(&preorder[1], rootIndex, &inorder[0], rootIndex);
    root->right = buildTree(&preorder[rootIndex + 1], preorderSize - rootIndex - 1, &inorder[rootIndex + 1], preorderSize - rootIndex - 1);
    
    return root;
}
