class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())   return false;
        for(int i=0;i<s.size();++i){
            string ans=s.substr(i)+s.substr(0, i);
            if(ans==goal)   return true;
        }
        return false;
    }
};

/*
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())   return false;
        return (s+s).find(goal)!=string::npos;
        
    }
};

有兩種方式，
第一種是直接合併兩個s字串，看裡面有沒有 goal
第二種方式是用旋轉加合併的方式，如果旋轉合併後的字串相等那就直接回傳true
*/