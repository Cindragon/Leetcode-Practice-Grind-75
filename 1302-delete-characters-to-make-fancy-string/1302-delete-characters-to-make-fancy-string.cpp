class Solution {
public:
    string makeFancyString(string s) {
        int count=1;
        string result;
        result+=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                count=1;
            }
            if(count<=2){
                result+=s[i];
            }
        }
        return result;
    }
};

/*
不用刪除字元，只要不要把大於三個的字元傳入result就好
最後回傳result
*/