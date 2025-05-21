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
判斷對稱其實就是比較左右兩棵子樹的所有節點是否可以翻轉成功
如果可以就代表對稱
而為了收集完左右兩邊子樹的所有節點資訊再做比較，要用後序遍歷(左右中)
接下來用遞迴的方式來比較
左右不對等回傳false的情況：
    左為空，右不為空
    左不為空，右為空
    左邊的值不等於右邊的值
左右相等回傳true： 左為空，右為空
最後由左子樹跟右子樹的外側節點比較，再由左子樹跟右子樹的內側節點比較
然後回傳result
*/