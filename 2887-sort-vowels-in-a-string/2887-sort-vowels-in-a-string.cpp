class Solution {
public:
    string sortVowels(string s) {
        string sv;
        vector<int> pos;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A'||s[i]=='a'||s[i]=='E'||s[i]=='e'||s[i]=='I'||s[i]=='i'||s[i]=='O'||s[i]=='o'||s[i]=='U'||s[i]=='u'){
                sv+=s[i];
                pos.push_back(i);
            }
        }
        sort(sv.begin(), sv.end());
        for(int i=0;i<sv.size();i++){
            s[pos[i]]=sv[i];
        }
        return s;
    }
};

/*
先將所有的母音蒐集起來
並且儲存他們的位置
接著將母音重新排序之後，再替換原本 s 字串的字元，並且透過儲存的位置索引值來替換
*/