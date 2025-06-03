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
private:
    void Traversal(TreeNode* node, vector<int>& path, vector<string>& result){
        path.push_back(node->val);
        if(node->left==NULL&&node->right==NULL){
            string sPath;
            int size=path.size();
            for(int i=0;i<size-1;i++){
                sPath+=to_string(path[i]);
                sPath+="->";
            }
            sPath+=to_string(path[size-1]);
            result.push_back(sPath);
            return;
        }
        if(node->left!=NULL){
            Traversal(node->left, path, result);
            path.pop_back();
        }
        if(node->right!=NULL){
            Traversal(node->right, path, result);
            path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        if(root==NULL) return result;
        Traversal(root, path, result);
        return result;
    }
};