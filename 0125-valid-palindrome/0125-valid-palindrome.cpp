class Solution {

private:
    string normalstring(string s){
        for (char &c : s) {
            if (isupper(c)) {
                c = tolower(c);
            }
        }
        string temp;
        for(char &c:s){
            if(c>='a'&&c<='z'||c>='0'&&c<='9')
            temp+=c;
        }
        return temp;
    }
public:
    bool isPalindrome(string s) {
        s=normalstring(s);
        int i=0, j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};