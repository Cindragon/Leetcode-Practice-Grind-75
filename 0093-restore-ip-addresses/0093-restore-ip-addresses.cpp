class Solution {
public:
    vector<string> res;
    void backtracking(string& s, int startIndex, int pointSum){
        if(pointSum==3){
            if(isValid(s, startIndex, s.size()-1)){
                res.push_back(s);
            }
            return;
        }
        for(int i=startIndex;i<s.size();i++){
            if(isValid(s, startIndex, i)){
                s.insert(s.begin()+i+1, '.');
                pointSum+=1;
                backtracking(s, i+2, pointSum);
                s.erase(s.begin()+i+1);
                pointSum-=1;
            }
            else
                break;
        }
        return;
    }
    bool isValid(string& s, int start, int end){
        if(start>end) {
            return false;
        }
        if(s[start]=='0'&&start!=end){
            return false;
        }
        int sum=0;
        for(int i=start;i<=end;i++){
            if(s[i]>'9'||s[i]<'0'){
                return false;
            }
            sum=sum*10+(s[i]-'0');
            if(sum>255){
                return false;
            }
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0);
        return res;
    }
};

/*
這題一樣用回溯算法，但有點難
因為要判斷字串是否符合 IP 的原則(開頭不得為零、數字不可以大於255)
首先一樣一個類別成員變數 res 來儲存我們要回傳的合法 IP 字串
接下來用回溯算法
1. 傳入參數：
    原本的字串(使用 & 傳入字串位址)，startIndex代表切割位置，pointSum 代表我們切了幾個位址
2. 終止條件：
    pointSum==3(代表我們已經切了三次)，那接下來還要再檢查最後一個字串
    若是合法就要把整個切割好的字串傳入 res
3. 單層遞迴邏輯：
    i 從 startIndex 開始，接著開始判斷切割出來的字串是否合法
    若是合法，加入一個點，pointSum+1
    接著繼續遞迴(startIndex 從 i+2 開始，因為有加了一個點)
    然後回溯(刪掉點跟pointSum-1)
    若是不合法直接結束本層遞迴

判斷字串是否合法的函數 isValid
傳入(字串s, 起始位置，終止位置)
for 迴圈從起始遍歷道中止
    如果起始大於終止，回傳 false
    如果起始為零然後 start!=end (代表是開頭為零的字串)，一樣回傳false
    如果為非數字字符一樣回傳 false
    總和加起來 >255 也回傳 false
    最後都通過會傳true
最後回傳res
*/