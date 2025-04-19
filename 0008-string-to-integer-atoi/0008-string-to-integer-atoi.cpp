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
有四個條件要判斷(透過字元的索引值來判斷)
用long long 來儲存 ans (怕溢位)
1. 前面有沒有空格，有的話 i++ ，如果最後全部都是' '就回傳 0
2. 前面有沒有正負符號(用int sign來存)，接著i++;
3. 判斷字元是否為數字(9>=s[i]-'0'=>0)，然後用ans=ans*10+s[i]的方式儲存答案
4. 乘上 sign 之後是否溢位，如果溢位就回傳最大或最小值
最後一樣回傳ans*sign
*/