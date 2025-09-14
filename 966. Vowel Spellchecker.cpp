class Solution {
public:
    auto isVowel(char ch)
    {
        ch = tolower(ch);
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }
    auto removeVowel(string s)
    {
        for(auto &ch : s)
            ch = isVowel(ch) ? '*' : ch;
        return s;
    }
    auto toLowerStr(string s)
    {
        for(auto &ch : s)
            ch = tolower(ch);
        return s;
    }
    string getCorrectStr(string find_s, unordered_set<string> &store, vector<pair<string, string>> &strs)
    {
        if(not store.count(find_s)) return "";
        for(auto [copy_s, original_s] : strs)
            if(copy_s == find_s) return original_s;
        return "";
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) 
    {
        vector<unordered_set<string>> wordlistOriginalStore(10), wordlistLowerStore(10);
        vector<vector<pair<string, string>>> storeRemoveVowelStr(10), storeLowerStr(10);
        
        for(auto &s : wordlist)
        {
            int n = s.size();

            auto lower_s =  toLowerStr(s);
            wordlistOriginalStore[n].insert(s);
            wordlistLowerStore[n].insert(lower_s);
            storeLowerStr[n].push_back({lower_s, s});

            auto removeVowel_s = removeVowel(lower_s);
            wordlistLowerStore[n].insert(removeVowel_s);
            storeRemoveVowelStr[n].push_back({removeVowel_s, s});
        }

        vector<string> ans;
        for(auto &s : queries)
        {
            int n = s.size();
            if(wordlistOriginalStore[n].count(s))
            {
                ans.push_back(s);
                continue;
            }

            auto lower_s = toLowerStr(s);
            string ans_s = getCorrectStr(lower_s, wordlistLowerStore[n], storeLowerStr[n]);

            if(ans_s == "")
                ans_s = getCorrectStr(removeVowel(lower_s), wordlistLowerStore[n], storeRemoveVowelStr[n]);
            
            ans.push_back(ans_s);
        }
        return ans;    
    }
};