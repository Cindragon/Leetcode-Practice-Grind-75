class Solution {
private:
    vector<string> ans;
    void backtracking(string s, int left, int right, int n){
        if(s.size()==n*2){
            ans.push_back(s);
            return;
        }
        if(left<n){ //還有幾個左括號可以放
            backtracking(s+'(', left+1, right, n);
        }
        if(right<left){ //放 ')' : 已放的左括號 > 已放的右括號
            backtracking(s+')', left, right+1, n);
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        backtracking("", 0, 0, n);
        return ans;
    }
};

/*
基本上也是用到回溯算法，變成要用 left 跟 right 來控制要加入幾個括號
重點是先加入左括號(後面加入右括號才能變成合法括號)，有括號則是在有放入左括號的情況下再放入右括號。
*/