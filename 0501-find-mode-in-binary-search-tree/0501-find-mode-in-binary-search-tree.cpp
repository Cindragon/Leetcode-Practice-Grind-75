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
    TreeNode* pre=NULL;
    vector<int> res;
    int count=0;
    int maxCount=0;
    void Traversal(TreeNode* root){
        if(root==NULL) return;
        Traversal(root->left);//左
        //中
        if(pre==NULL) count=1;
        else if(pre->val==root->val) count++;
        else count=1;
        if(count==maxCount){
            res.push_back(root->val);
        }
        else if(count>maxCount){
            res.clear();
            res.push_back(root->val);
            maxCount=count;
        }
        pre=root;
        //中
        Traversal(root->right); //右
    }

public:
    vector<int> findMode(TreeNode* root) {
        Traversal(root);
        return res;
    }
};

/*
BST就一樣用中序遍歷
首先定義前一個節點、res陣列加上記數count跟最大記數maxCount
如果root==NULL return 空陣列
如果pre==NULL 先讓count=1
或是如果 pre跟root的值相等 count++
又或是(值不相等) count重設為1(重新計算)
然後將count跟maxCount做比較
如果count==maxCount 把root->val加到res(因為眾數可能不只一個)
如果count更大(代表找到另一個眾數)
將陣列清空，重新加入並且更新maxCount的數字
最後回傳res
*/