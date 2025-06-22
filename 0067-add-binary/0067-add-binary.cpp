class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        // 從兩個字串的最後一位開始加，直到兩個都加完且沒有進位為止
        while(i>=0||j>=0||carry!=0){
            int sum=carry;
            if(i>=0) sum+=a[i]-'0';
            if(j>=0) sum+=b[j]-'0';
            res+=sum%2+'0';
            carry=sum/2;
            i--;
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/*
說明：
1. 從字串最後一位（低位）開始進行加法。
2. 使用 i 和 j 分別指向 a 和 b 的最後一個字元。
3. 每次迴圈先把 carry 加進 sum，然後再加上 a[i] 和 b[j] 的數值（若 i/j >= 0）。
4. sum % 2 表示目前位元的結果（因為二進位最多加出 3，%2 會是 0 或 1）。
5. sum / 2 表示進位（0 或 1），保留給下一輪使用。
6. 將每一輪計算的位元接到 res 字串尾端。
7. 加完後因為是從低位到高位加，要反轉字串 res 才是正確的答案。
*/