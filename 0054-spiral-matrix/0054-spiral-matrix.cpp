class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        int n=matrix[0].size();
        int top=0, bottom=m-1, left=0, right=n-1;
        while(top<=bottom&&left<=right){
            for(int i=left;i<=right;i++){
                res.push_back(matrix[top][i]);
            }
            top++;
            if(top<=bottom){
                for(int i=top;i<=bottom;i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};

/*
用螺旋順序輸出陣列的各個數，最重要的是邊界處理的部分(左閉右閉的方式)
以四個變數分別代表上下左右
先從左到右輸出，輸出完畢後將 top++(最上面這排輸出完畢)
接著從上到下，輸出完畢後一樣將 right--(最右邊已輸出完畢)
從右到左，需要注意是在 top<=bottom 的情況下，不然有可能重複輸出數字(最後bottom--)
最後再下到上，一樣需要注意是在 left<=right，最後 left++
結束後回傳 res
*/