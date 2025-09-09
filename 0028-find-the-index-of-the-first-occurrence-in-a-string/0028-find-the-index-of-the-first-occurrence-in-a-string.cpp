class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();
        for(int i=0;i<=m-n;i++){
            int j=0;
            while(j<n&&haystack[i+j]==needle[j]){
                j++;
            }
            if(j==n)   return i;
        }
        return -1;
    }
};

/*
先求出兩個字串的長度，接著從頭開始遍歷 haystack 字串
並且用一個變數 j 來遍歷 needle 字串
在 j<n && 字元相同的時候 j++，一旦 j==n 直接 return i(出現 needle 字串的第一個索引值)
*/