class Solution {
public:
    int myAtoi(string s) {
        int i=0, n=s.size(), sign=1;     
        long long ans=0;
        while(i<n && s[i]==' '){
            i++;
        }
        if(i==n) return 0;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+') i++;
        while(i<n && s[i]-'0'>=0 && s[i]-'0'<=9){
            ans=ans*10+(s[i]-'0');
            if(sign*ans>INT_MAX) return INT_MAX;
            if(sign*ans<INT_MIN) return INT_MIN;
            i++;
        }
        return (int)(ans*sign);
    }
};

/*
整體邏輯共分為四個判斷步驟（透過字元索引 i 進行掃描）：
為避免整數溢位，使用 long long 儲存中間結果 ans。

1. 忽略字串前導空格：
   持續遞增索引 i，直到遇到非空格字元。
   若整串皆為空格，則直接回傳 0。

2. 處理正負號：
   如果當前字元為 '+' 或 '-'，使用變數 sign 記錄正負，
   然後將索引 i 向後移動一位。

3. 將連續的數字字元轉為整數：
   每次將數字 s[i] 轉換成對應整數，並累加至 ans：
   ans = ans * 10 + (s[i] - '0')
   若遇到非數字字元，則中止處理。

4. 檢查是否溢位：
   每次累加後即時檢查 ans * sign 是否超出 int 範圍。
   若超過上限，回傳 INT_MAX；
   若低於下限，回傳 INT_MIN。

最後回傳 ans * sign，即轉換後的整數值。
*/