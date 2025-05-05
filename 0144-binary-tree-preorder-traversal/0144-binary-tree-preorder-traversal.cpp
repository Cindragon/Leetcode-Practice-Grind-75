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
    void Traversal(TreeNode* root, vector<int>& ans){
        if(root==nullptr) return;
        ans.push_back(root->val);
        Traversal(root->left, ans);
        Traversal(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        Traversal(root, ans);
        return ans;
    }
};
/*
前序遍歷：中左右
用一個函式來遍歷整棵二元樹
到底就return
傳入中節點的值
然後遍歷左節點再來是右節點
最後回傳vector
*/