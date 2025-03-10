class Solution {
    public:
        auto isVowel(char &ch)
        {
            return (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u');
        }
    
        long long countOfSubstrings(string word, int k) 
        {
            long ans = 0, n = word.size();
            unordered_map<char, int> vowel; 
    
            int lastSeenConsonant = n;
            vector<int> nextConsonant(n); 
            for(int i = n - 1; i >= 0; i--)
            {
                nextConsonant[i] = lastSeenConsonant;
                if(not isVowel(word[i])) lastSeenConsonant = i;
            }
    
            int i = 0, j = 0, consonant = 0;
            while(j < n)
            {
                if(isVowel(word[j])) vowel[word[j]] += 1;
                else consonant += 1;
    
                while(consonant > k)
                {
                    if(isVowel(word[i])) 
                    {
                        vowel[word[i]] -= 1;
                        if(vowel[word[i]] == 0) vowel.erase(word[i]);
                    }
                    else consonant -= 1;
                    i += 1;
                }
    
                while(vowel.size() == 5 and consonant == k)
                {
                    ans += nextConsonant[j] - j;
                    if(isVowel(word[i])) 
                    {
                        vowel[word[i]] -= 1;
                        if(vowel[word[i]] == 0) vowel.erase(word[i]);
                    }
                    else consonant -= 1;
                    i += 1;
                }
                j += 1;
    
            }  
            return ans;
        }
    };