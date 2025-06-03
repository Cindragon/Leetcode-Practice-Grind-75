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
    int getHeight(TreeNode* node){
        if(node==NULL) return 0;
        int leftHeight=getHeight(node->left);
        if(leftHeight==-1) return -1;
        int rightHeight=getHeight(node->right);
        if(rightHeight==-1) return -1;
        int result;
        if(abs(leftHeight-rightHeight)>1) return -1;
        else result=1+max(leftHeight, rightHeight);
        return result;
    }
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root)==-1?false:true;
    }
};

/*
一樣用後序遍歷來看計算左右子樹的高度看是否為平衡二叉樹
在getHeight函式中
計算左子樹跟右子樹的高度，如果其中有一棵樹高度回傳為-1
說明這棵樹已經不是平衡二叉樹
最後回傳到中間節點時
如果左右子樹相減>1即返回-1(非平衡二叉樹)
其他則是將回傳1(底層)+左右子樹的最大值(看哪一邊比較高)
最後用三元運算子回傳 true or false
*/