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

/**/