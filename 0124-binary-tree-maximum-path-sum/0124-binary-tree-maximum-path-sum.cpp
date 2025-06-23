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
    int dfs(TreeNode* root, int& s){
        if(root==NULL) return 0;
        int leftSum=max(dfs(root->left, s), 0);
        int rightSum=max(dfs(root->right, s), 0);
        int currSum=root->val+leftSum+rightSum;
        s=max(s, currSum);
        return root->val+max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int s=INT_MIN;
        dfs(root, s);
        return s;
    }
};

/*
跟 524 diameter of binarytree 一樣
用dfs的遞迴方式處理
終止條件：
    如果 root==NULL return 0
單層遞迴邏輯：
    左邊的和= 左子樹的值與 0 比較大小(如果是負數就不要加上去)
    右邊的和同理
    接著處理中間的 currSum=左邊加上右邊再加上自己root->val
    s 進行更新，取 s 跟 currSum 的最大值
    最後要回傳的是 root->val 加上左或右的最大值
    (回傳給上一層時，只能取「單邊路徑」，不能取左右兩邊合併，因為這樣就不能繼續向上延伸。)
才能得到整條路徑總和的最大值
*/