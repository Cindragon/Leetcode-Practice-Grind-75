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
    TreeNode* pre;
    vector<int> res;
    int count=0;
    int maxCount=0;
    void Traversal(TreeNode* root){
        if(root==NULL) return;
        Traversal(root->left);
        if(pre==NULL) count=1;
        else if(pre->val==root->val) count++;
        else count=1;
        if(count==maxCount){
            res.push_back(root->val);
        }
        else if(count>maxCount){
            res.clear();
            res.push_back(root->val);
            maxCount=count;
        }
        pre=root;

        Traversal(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        Traversal(root);
        return res;
    }
};