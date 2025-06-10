/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 1)
            return new TreeNode(nums[0]);
        //中
        int maxValue = 0;
        int index;
        for (int i = 0; i < nums.size(); i++) {
            if (maxValue < nums[i]){
                maxValue = nums[i];
                index=i;
            }
        }
        TreeNode* root = new TreeNode(maxValue);
        //中
        if (index > 0) {    //左
            vector<int> prefix(nums.begin(), nums.begin() + index);
            root->left = constructMaximumBinaryTree(prefix);
        }
        if (index < nums.size() - 1) {  //右
            vector<int> suffix(nums.begin()+index+1, nums.end());
            root->right = constructMaximumBinaryTree(suffix);
        }
        return root;
    }
};
/*
這次使用前序遍歷(中左右)來建構最大二元樹
首先判斷如果size=1 代表只有根節點，就直接回傳TreeNode root就好
接著要判斷陣列中的最大數值在哪裡(根節點)，從中去切割左右子樹
接著要判斷左右兩邊的陣列是否為空，如果不是就建構新的陣列
並且遞迴建構左右兩棵子樹。
最後回傳node
*/