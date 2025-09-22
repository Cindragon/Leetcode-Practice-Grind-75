class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int top=0, bottom=m-1, row=-1;
        while(top<=bottom){
            int mid=top+(bottom-top)/2;
            if(matrix[mid][0]>target){
                bottom=mid-1;
            }
            else if(target>matrix[mid][n-1]){
                top=mid+1;
            }
            else{
                row=mid;
                break;
            };
        }
        if(row==-1) return false;

        int left=0, right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(matrix[row][mid]==target)   return true;
            else if(matrix[row][mid]<target)   left=mid+1;
            else    right=mid-1;
        }
        return false;
    }
};

/*
做兩次 Binary Search，找到行跟列中間的索引值
先從上下來找 target 在第幾行，找到第幾行之後儲存下來
接著從左右開始找，看有沒有找到，如果找到回傳 true 沒找到回傳 false
*/