class Solution {
public:
    bool isValid(string word) 
    {
        if(word.size() < 3) return 0;

        string vowel = "aeiou";
        bool isDigit = 0, isVowel = 0, isConsonant = 0, isUpper = 0, isLower = 0;
        for(const char &ch : word)
        {
            if(ch == '@' or ch == '#' or ch == '$') return 0;

            if(isdigit(ch)) 
            {
                isDigit = 1;
                continue;
            }
            else if(isupper(ch)) isUpper = 1;
            else isLower = 1;

            if(vowel.find(tolower(ch)) != -1) isVowel = 1;
            if(vowel.find(tolower(ch)) == -1) isConsonant = 1;
        }
        return (isDigit or isUpper or isLower) and isConsonant and isVowel;
    }
};