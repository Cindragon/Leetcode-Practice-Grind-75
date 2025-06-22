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
        int digit=digits[index]-'0';
        string letter=letterMap[digit];
        for(int i=0;i<letter.size();i++){
            s.push_back(letter[i]);
            backtracking(digits, index+1);
            s.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        s.clear();
        res.clear();
        if(digits=="") return res;
        backtracking(digits, 0);
        return res;
    }
};