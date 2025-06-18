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
    TreeNode* bulideBST(vector<int>& nums, int left, int right){
        if(left>right) return NULL;
        int mid=left+(right-left)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=bulideBST(nums, left, mid-1);
        root->right=bulideBST(nums, mid+1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bulideBST(nums, 0, nums.size()-1);
    }
};

/*
解題思維為：不斷從中間分割，然後用遞迴的方式處理左右子樹，來構建一棵平衡二元樹
用一個函式來建構二元樹
首先確定左右邊界(陣列開始與結束)
以左閉右閉的形式來處理邊界
如果左大於右，說明已經建構完這棵樹了，直接回傳NULL
接下來先找到中間值並且建構根節點
然後遞迴建構左右子樹(注意邊界值)
最後回傳root
*/