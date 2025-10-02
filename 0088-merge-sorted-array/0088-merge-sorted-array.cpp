class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1, k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]<nums2[j]){
                nums1[k--]=nums2[j--];
            }
            else{
                nums1[k--]=nums1[i--];
            }
        }
        while(j>=0){
            nums1[k--]=nums2[j--];
        }
    }
};

/*
用雙指針的寫法，從後面開始覆蓋 nums1 的尾部
將兩個陣列的數字從尾巴開始比較
    如果 nums2[j]>num1[i]   nums1[k]=nums2[j]   k--, j--
    反之則 nums1[k]=nums[i] k--, i--
如果最後 j>0 (代表 nums2 還有元素沒被放進去)，於是一樣將元素放到 nums1[k]
*/