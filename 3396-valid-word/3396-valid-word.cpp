class Solution {
public:
    bool isValid(string word) {
        bool vowel=false;
        bool consonant=false;
        if(word.size()<3) return false;
        for(int i=0;i<word.size();i++){
            if(isupper(word[i])){
                word[i]=tolower(word[i]);
            }
        }
        for(const auto&c:word){
            if(!isdigit(c)&&!isalpha(c)) return false;
            if(isalpha(c)){
                if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
                    vowel=true;
                }
                else
                    consonant=true;
            }
        }
        return vowel&&consonant;
    }
};