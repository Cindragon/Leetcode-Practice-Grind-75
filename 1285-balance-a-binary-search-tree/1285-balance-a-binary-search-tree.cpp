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
    vector<int> nums;
    void traversal(TreeNode* root){
        if(root==NULL)  return;
        traversal(root->left);
        nums.push_back(root->val);
        traversal(root->right);
    }
    TreeNode* buildTree(int left, int right){
        if(left>right) return nullptr;
        int mid=left+(right-left)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=buildTree(left, mid-1);
        node->right=buildTree(mid+1, right);
        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        nums.clear();
        traversal(root);
        return buildTree(0, nums.size()-1);
    }
};

/*
先用一個陣列，以中序遍歷將 BST 的值都記錄在 nums
接下來要進行平衡，從中間點開始建立一棵樹的根節點
並且用二元搜尋法的方式，將左邊跟右邊的子樹都建起來
*/