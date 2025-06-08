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
    vector<vector<int>> result;
    vector<int> path;
    void Traversal(TreeNode* root, int count){
        if(root->left==NULL&&root->right==NULL){
            if(count==0){
                result.push_back(path);
                return;
            }
            else return; //遇到葉子節點值不為0就返回
        }
        if(root->left){
            path.push_back(root->left->val);
            count-=root->left->val;
            Traversal(root->left, count);
            count+=root->left->val;
            path.pop_back();
        }
        if(root->right){
            path.push_back(root->right->val);
            count-=root->right->val;
            Traversal(root->right, count);
            count+=root->right->val;
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        result.clear();
        path.clear();
        if(root==NULL) return result;
        path.push_back(root->val);
        Traversal(root, targetSum-root->val);
        return result;
    }
};
/*
使用前中後序都可以(因為不會涉及到處理中節點的邏輯)
定義兩個全域變數來儲存結果跟路徑
一開始把根節點先加入，接下來開始遞迴
如果遇到葉子節點然後最後count==0，代表找到了，把path加入result，沒有就return
接著一樣遍歷左右子樹
一邊加入path一邊count減去root->left->val或是root->right->val
一邊相減的過程也要記得回溯(因為有可能到另一條支線)
把值加回去的同時也要把原本節點的值彈出
*/