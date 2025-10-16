class Solution {
private:
    bool isPalindrome(const string&s, int left, int right){
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else    return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int left=0, right=s.size()-1;
        bool flag=false;
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else
                return isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1);
        }
        return true;
    }
};

/*
在這題中，因為只能刪除一個字元，因此如果我們遇到了不一樣的字元，就要分成左邊跟右邊去看
如果有一邊是 true 那就可以 return true
*/