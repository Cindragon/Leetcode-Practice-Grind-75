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
    TreeNode* pre=NULL;
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        bool left=isValidBST(root->left);
        if(pre!=NULL&&pre->val>=root->val) return false;
        pre=root;
        bool right=isValidBST(root->right);
        return left&&right;
    }
};

/*
遞迴法用中序遍歷的方式來處理
首先定義一個最小值maxValue(long long型態)
判斷終止條件 如果root==NULL return true
接著是遍歷左邊
中間的值如果比maxValue大就用root的值取代
不然就回傳false
最後遍歷右邊
然後回傳 left&&right(都是true就代表是BST)

class Solution {
public:
    long long maxValue=LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        bool left=isValidBST(root->left);
        if(root->val>maxValue){
            maxValue=root->val;
        }
        else
            return false;
        bool right=isValidBST(root->right);
        return left&&right;
    }
};

另一種解法就是儲存前一個節點的值
然後再進行比較
如果pre!=NULL&&pre的值大於等於root的值(說明不是BST) 回傳false
*/