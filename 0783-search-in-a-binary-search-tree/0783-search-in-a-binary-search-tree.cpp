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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL||root->val==val) return root;
        if(root->val>val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }
};
/*
運用二元搜索樹的特性來找回傳值
如果大於val往右邊找，小於往左邊找
最後都沒有就return NULL(一開始的root==NULL)就回傳了
*/

/*
另一種解法(迭代法)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL){
            if(val<root->val) root=root->left;
            else if(val>root->val) root=root->right;
            else return root;
        }
        return NULL;
    }
};
*/