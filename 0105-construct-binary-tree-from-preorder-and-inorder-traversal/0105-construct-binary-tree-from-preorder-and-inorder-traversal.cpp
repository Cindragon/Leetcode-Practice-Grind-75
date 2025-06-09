/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* Traversal(vector<int>& preorder, vector<int>& inorder){
        int rootvalue=preorder[0];
        TreeNode* root=new TreeNode(rootvalue);
        if(preorder.size()==1) return root;
        int index;
        for(index=0;index<inorder.size();index++){
            if(inorder[index]==rootvalue) break;
        }
        vector<int> leftinorder(inorder.begin(), inorder.begin()+index);
        vector<int> rightinorder(inorder.begin()+index+1, inorder.end());
        vector<int> leftpreorder(preorder.begin()+1, preorder.begin()+1+leftinorder.size());
        vector<int> rightpreorder(preorder.begin()+1+leftinorder.size(), preorder.end());
        if(!leftpreorder.empty())
            root->left=Traversal(leftpreorder, leftinorder);
        if(!rightpreorder.empty())
            root->right=Traversal(rightpreorder, rightinorder);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return NULL;
        return Traversal(preorder, inorder);
    }
};