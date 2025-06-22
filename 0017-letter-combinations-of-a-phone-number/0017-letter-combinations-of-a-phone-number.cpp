class Solution {
public:
    const string letterMap[10]={
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> res;
    string s;
    void backtracking(string digits, int index){
        if(index==digits.size()){
            res.push_back(s);
            return;
        }
        int digit=digits[index]-'0';    //找到目前digit字串index的字元並且轉成數字
        string letter=letterMap[digit]; //將數字轉變成這個數字對應的英文字串
        for(int i=0;i<letter.size();i++){
            s.push_back(letter[i]);
            backtracking(digits, index+1);  //下一個digit字串的字元
            s.pop_back();   //回溯
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        s.clear();
        res.clear();
        if(digits.size()==0) return res;
        backtracking(digits, 0);
        return res;
    }
};

/*
需要先做一張映射表，將數字轉換成字母(0跟1因為沒有字母就先設"")
接下來一樣要用回溯算法
傳入參數：digit 字串還有 index(代表的是要從digit的第幾個字元開始轉換成字母)
終止條件：如果index==digit.size()，代表遍歷完一次字串長度了，將我們收集到的字母字串 s 加入 res
單層遞迴邏輯：
    1. 轉換字元成數字
    2. 轉換數字成英文字串
    3. for 迴圈遍歷，把字母加入 s ，接著用 backtracking，index+1 代表要轉換下一個索引值的字母
    4. 回溯
最後如果digit為空，直接回傳空陣列
*/