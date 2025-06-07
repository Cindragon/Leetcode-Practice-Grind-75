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
    int maxDepth=INT_MIN;
    int result;
    void Traversal(TreeNode* root, int depth){
        if(root==NULL) return;
        if(root->left==NULL&&root->right==NULL){
            if(depth>maxDepth){
                maxDepth=depth;
                result=root->val;
            }
            return;
        }
        if(root->left){ //=Traversal(root->left, depth+1);
            depth++;
            Traversal(root->left, depth);
            depth--;
        }
        if(root->right){ //=Traversal(root->right, depth+1);
            depth++;
            Traversal(root->right, depth);
            depth--;
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        Traversal(root, 0);
        return result;
    }
};

/*
先定義兩個全域變數(maxdepth最大深度, result是要更新的最左下角的值)
用遞迴法來寫，用前中後序都可以
因為最重要的是在深度最大的時候，找到最左下角的值
終止條件為
找到葉子節點的時候，如果depth>maxdepth，要更新深度，並且result會等於這個節點的值
向左跟向右遞迴時要記得回溯，才能正確更新深度
最後回傳result
*/

/*
另一種是用層次遍歷(BFS)的方式來寫
只要找到每一層最左邊的值就好
最後再回傳
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if(root==NULL) return 0;
        que.push(root);
        int result=root->val;
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode* node=que.front();
                que.pop();
                if(i==0) result=node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return result;
    }
};
*/