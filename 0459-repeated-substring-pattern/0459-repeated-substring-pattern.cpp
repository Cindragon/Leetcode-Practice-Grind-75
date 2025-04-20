class Solution {
public:
    void getNext(const string&s, int* next){
        next[0]=0;
        int j=0;
        for(int i=1;i<s.size();i++){
            while(j>0 && s[i]!=s[j]){
                j=next[j-1];
            }
            if(s[i]==s[j]){
                j++;
            }
            next[i]=j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if(s.size()==0) return false;
        int next[s.size()];
        getNext(s, next);
        int len=s.size();
        if(next[len-1]!=0 &&(len%(len-next[len-1]))==0){
            return true;
        }
        else
            return false;
    }
};

/*
用 KMP 算法去找字串是否由重複的子字串組成
最長相等前後綴的規則：當一個字符是由重複子字串組成的，最長相等前後綴不包含的子字串就是最短重複子字串(最小重複單位)
getNext 函數來找最長相等前後綴的長度
next[i] 表示 s[0...i] 這一段中，前綴和後綴最長匹配的長度
求出來之後
如果next[len-1]!=0，說明有最長相等前後綴，長度為next[len-1]
如果 len(字串長度) 可以被 len-next[len-1] 整除(最短重複子字串長度)，說明該字串由重複的子字串組成

範例說明：
- s = "abab"
  -> next = [0,0,1,2]
  -> next[3] = 2, len = 4
  -> 4 % (4 - 2) == 0 → 是重複的 ("ab" * 2)

- s = "abcabcabc"
  -> next = [0,0,0,1,2,3,4,5,6]
  -> next[8] = 6, len = 9
  -> 9 % (9 - 6) == 0 → 是重複的 ("abc" * 3)

- s = "abcd"
  -> next = [0,0,0,0]
  -> next[3] = 0 → 沒有重複
*/