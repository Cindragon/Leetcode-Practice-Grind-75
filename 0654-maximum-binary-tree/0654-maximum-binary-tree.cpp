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
這段程式使用前序遍歷（中 → 左 → 右）來遞迴建構最大二元樹。

步驟如下：
1. 如果陣列大小為 1，代表只剩一個節點，直接建立並回傳該節點。
2. 找出陣列中最大值及其索引位置，作為目前子樹的根節點（root）。
3. 將陣列根據最大值位置切成左、右子陣列：
   - 左半邊作為左子樹的輸入。
   - 右半邊作為右子樹的輸入。
4. 遞迴構建左右子樹並接到根節點上。
5. 回傳目前構建好的根節點。
*/