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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        TreeNode*left=root->left;
        TreeNode*right=root->right;
        int leftDepth=0, rightDepth=0;
        while(left){
            left=left->left;
            leftDepth++;
        }
        while(right){
            right=right->right;
            rightDepth++;
        }
        if(leftDepth==rightDepth) return (2<<leftDepth)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
/*
用後序遍歷來算樹節點
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int count=0;
        int left=countNodes(root->left);
        int right=countNodes(root->right);
        count=1+left+right;
        return count;
    }
};

或是利用完全二叉樹的特性(節點數為2^層數-1)
計算左子樹跟右子樹的深度
如果深度一樣，那麼節點的個數就是 2<<深度-1
最後再將左右子樹的個數相加再+1
具體做法：
1. 分別計算左子樹最左深度與右子樹最右深度。
2. 如果兩者深度相同，代表這是一棵滿二叉樹，可以直接回傳節點總數。
3. 如果不相同，就繼續遞迴左右子樹，回傳 1 + 左子樹節點數 + 右子樹節點數。

注意：
- (1 << (depth + 1)) 是位元運算，代表 2^(depth + 1)，比 pow 更快更安全。
2<<1其實等於2^2，所以leftDepth要從0開始計算
*/