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
    void Traversal(TreeNode* node, vector<int>& path, vector<string>& result){
        path.push_back(node->val); //中
        if(node->left==NULL&&node->right==NULL){
            string sPath;
            int size=path.size();
            for(int i=0;i<size-1;i++){
                sPath+=to_string(path[i]);
                sPath+="->";
            }
            sPath+=to_string(path[size-1]);
            result.push_back(sPath);
            return;
        }
        if(node->left!=NULL){ //左
            Traversal(node->left, path, result);
            path.pop_back(); //回溯(把先前的點彈出)
        }
        if(node->right!=NULL){ //右
            Traversal(node->right, path, result);
            path.pop_back(); //回溯(把先前的點彈出)
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        if(root==NULL) return result;
        Traversal(root, path, result);
        return result;
    }
};

/*
使用「前序遍歷」搭配「回溯法」來找出所有從根節點到葉節點的路徑。

1. 每到一個節點，就將其值加入 path 中（中）。
2. 如果該節點為葉節點（左右子樹皆為 NULL），
   將 path 轉換成字串格式並加入 result。
3. 遞迴遍歷左子樹與右子樹（左→右）。
4. 回溯：在遞迴返回後，將剛加入的節點從 path 中移除，恢復上一層狀態。
5. 最後回傳儲存所有路徑字串的 result。

注意：
- 一定要在一開始將節點加入 path，否則葉節點會漏記。
- 回溯是為了避免 path 留下其他路徑的殘留。
*/