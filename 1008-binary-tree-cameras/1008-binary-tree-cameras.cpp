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
    int result=0;
    int traversal(TreeNode* root){
        if(root==NULL) return 2;
        int left=traversal(root->left);
        int right=traversal(root->right);
        if(left==2&&right==2) return 0;
        if(left==0||right==0){
            result++;
            return 1;
        }
        if(left==1||right==1) return 2;
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(traversal(root)==0) result++;
        return result; 
    }
};

/*
貪心在要用最少的攝影機監控整棵二元樹
整棵二元樹可以有三種狀態：
    狀態一：無覆蓋=0
    狀態二：有攝影機=1
    狀態三：有覆蓋=2
接下來要用後序遍歷的方式來遍歷整棵二元樹
為了統一規定(在葉子節點的父節點放攝影機)，因此遍歷到空節點時，需要返回有覆蓋
接著就要考慮三種狀況：
    1. 左節點跟右節點都是有覆蓋的，此時回傳父節點為無覆蓋
    2. 左節點或右節點其中一個是無覆蓋的，此時父節點要加一個攝影機，並且回傳1
    3. 左節點或有節點是有攝影機的，此時回傳父節點為有覆蓋
    
最後，如果整棵樹的根節點仍為「未覆蓋」狀態（返回 0），則我們必須額外在根節點安裝攝影機（result++）。
時間複雜度：O(n)，其中 n 是節點數量。
空間複雜度：O(h)，h 是樹的高度，用於遞迴棧。
*/