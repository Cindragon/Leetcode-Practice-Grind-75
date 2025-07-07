class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s=to_string(n);
        int flag=s.size();
        for(int i=s.size()-1;i>0;i--){
            if(s[i-1]>s[i]){
                s[i-1]--;
                flag=i;
            }
        }
        for(int i=flag;i<s.size();i++){
            s[i]='9';
        }
        return stoi(s);
    }
};

/*
找到最大的單調遞增數字，先將n轉變為字串(可以直接讀取單獨某一位數字)
使用flag來記錄從這一位元開始全部變成9
處理邏輯是：兩兩相互比較
如果前一位數字大於後面一位數字，將前一位-1，並且記錄flag的位置
最後再重新遍歷，將flag以後的位元都改成9
最後回傳轉回int的型態
*/