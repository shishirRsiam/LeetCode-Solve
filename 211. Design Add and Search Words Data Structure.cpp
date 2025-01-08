class WordDictionary {
public:
    unordered_set<string> store;
    unordered_map<int, unordered_set<string>> countingStore;
    WordDictionary() {}
    void addWord(string word) 
    {
        store.insert(word);
        countingStore[word.size()].insert(word);
    }
    
    bool search(string word) 
    {
        if(store.count(word)) return true;

        int n = word.size(), dot = false;
        for(int i = 0; i < n; i++)
        {
            if(dot or not word[i]) break;
            if(word[i] == '.') dot = true;
        }
        if(not dot) return false;
        
        for(auto s : countingStore[n])
        {
            bool isFound = true;
            for(int i = 0; i < n; i++)
            {
                if(word[i] == '.') continue;
                if(word[i] != s[i]) 
                {
                    isFound = false;
                    break;
                }
            }
            if(isFound) return true;
        }
        return false;
    }
};