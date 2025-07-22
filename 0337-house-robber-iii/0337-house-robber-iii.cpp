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
    vector<int> robTree(TreeNode* root){
        if(root==NULL)  return vector<int>{0, 0};
        vector<int> leftRob=robTree(root->left);
        vector<int> rightRob=robTree(root->right);
        int val1=root->val+leftRob[0]+rightRob[0];  //偷當前節點
        int val2=max(leftRob[0], leftRob[1])+max(rightRob[0], rightRob[1]);     //不偷當前節點
        return {val2, val1};
    }
    int rob(TreeNode* root) {
        vector<int> res=robTree(root);
        return max(res[0], res[1]);     //{不偷, 偷}
    }
};

/*
這題使用動態規劃的方式來解決，在遍歷時採用遞迴+後序遍歷的方式由下往上遍歷
回傳值與傳入參數：回傳 dp 陣列並且傳入 root
dp[0] 為不偷該節點的最大總額，dp[1] 為偷該節點的最大總額
終止條件：若是 root 為 NULL 回傳空陣列{0, 0}
遍歷順序：左右中
中間節點便要處理 dp 數組的值
val1 為偷當前節點，也就是加入本節點的值之後加上左右孩子都不偷的值
val2 為不偷當前節點，那最大值就會是左右孩子的最大值相加
最後回傳 val1 跟 val2
*/