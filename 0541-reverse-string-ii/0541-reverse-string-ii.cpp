class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        for(int i=0;i<n;i+=2*k){
            int left=i;
            int right=min(i+k-1, n-1);
            while(left<right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

/*
這題用到了雙指針，外層迴圈裡要+=2k
讓 left=i, right=min(i+k-1, s.size()-1)
使用 min() 是為了確保 right 不會超出字串邊界，
如果剩下的長度不足 k，就只反轉剩下的那幾個字元
最後在 left<right 的情況下 swap 完 k 個字元之後 return s
*/