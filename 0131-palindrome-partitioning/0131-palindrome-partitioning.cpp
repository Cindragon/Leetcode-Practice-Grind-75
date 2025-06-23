class Solution {
public:
    vector<string> path;
    vector<vector<string>> res;
    void backtracking(const string& s, int startIndex){
        if(startIndex>=s.size()){
            res.push_back(path);
            return;
        }
        for(int i=startIndex;i<s.size();i++){
            if(isPalindrome(s, startIndex, i)){ //使用自定義函數來檢查目前的字串是不是回文字串
                string subs=s.substr(startIndex, i-startIndex+1); // 從 startIndex 到 i 切出一個回文子字串
                path.push_back(subs);
            }
            else
                continue;
            backtracking(s, i+1);
            path.pop_back();
        }
        return;
    }
    bool isPalindrome(const string& s, int begin, int end){
        for(int i=begin, j=end;i<=j;i++, j--){
            if(s[i]!=s[j]) return false;   
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
};
/*
使用回溯法來寫
使用類別成員變數 path 儲存目前切割路徑，res 用來儲存所有合法解
參數傳入：
    原本的字串以及startIndex(用來確認切割的起始位置)
終止條件：
    若 startIndex 已超過字串長度，代表已成功切完，將 path 加入 res。
單層遞迴邏輯：
    i=startIndex
    首先使用自定義的回文函數來檢查目前的子字串是否為回文
    如果是，就複製這個字串然後傳到加到path
    接著遞迴繼續加入字母，並且記得回溯
最後一樣回傳res
*/