class MagicDictionary {
public:
    unordered_map<int, vector<string>> store;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) 
    {
        for(auto &s : dictionary)
            store[s.size()].push_back(s);    
    }
    
    bool search(string searchWord) 
    {
        int n = searchWord.size();
        auto all_string = store[n];
        for(auto s : all_string)
        {
            int count = 0;
            for(int i = 0; i < n; i++)
            {
                if(s[i] != searchWord[i]) count += 1;
                if(count > 1) break;
            }
            if(count == 1) return true;
        }
        return false;    
    }
};