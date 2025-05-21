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
    bool iscompare(TreeNode* left, TreeNode* right){
        if(left==NULL&&right!=NULL) return false;
        else if(left!=NULL&&right==NULL) return false;
        else if(left==NULL&&right==NULL) return true;
        else if(left->val!=right->val) return false;
        else{
            bool outside=iscompare(left->left, right->right);
            bool inside=iscompare(left->right, right->left);
            bool result=outside&&inside;
            return result;
        }
    }
    bool isSymmetric(TreeNode* root) {
        return iscompare(root->left, root->right);
    }
};

/*
這題的目標是判斷一棵二元樹是否為對稱樹（Symmetric Tree），
其本質是判斷「左子樹」與「右子樹」是否為鏡像對稱。

解法思路：
- 使用遞迴比較左、右兩棵子樹的對應節點是否一致。
- 若左右子樹為鏡像對稱，則整棵樹為對稱。

比較規則如下（任一條件不符合則不對稱）：
1. 左節點為空、右節點不為空 → false
2. 左節點不為空、右節點為空 → false
3. 左右皆為空 → true（對稱的終止條件）
4. 左右節點值不同 → false
5. 遞迴比較兩棵子樹的：
   - 外側節點（left->left 與 right->right）
   - 內側節點（left->right 與 right->left）

最後回傳內側與外側都對稱的結果。
→ 使用的是「後序遍歷」邏輯：左 → 右 → 中（比較後才回傳）。
*/