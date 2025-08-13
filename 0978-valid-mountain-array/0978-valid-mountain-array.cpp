class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3) return false;
        int left=0, right=n-1;
        while(left+1<n&&arr[left+1]>arr[left]){
            left++;
        }
        while(right-1>=0&&arr[right-1]>arr[right]){
            right--;
        }
        return left>0 && right< n-1&& left==right;
    }
};

/*
用左右兩個變數來看是不是符合山頂陣列
長度<3 代表不是山，直接return false
接下來要用雙指針的方式，找到山頂的位置
left+1<n 且 arr[left+1]>arr[left] left++(往山頂走)
right-1>=0 且 arr[right-1]>arr[right](一樣往山頂走)
回傳 left>0(不能是第一個元素) && right<n-1(山頂不是最後一個) 而且left==right(一起走到山頂)
*/