class Solution {
public:
    bool makeEqual(vector<string>& words) 
    {
        unordered_map<char, int> store;
        for(auto &word : words)
            for(auto &ch : word) store[ch] += 1;

        int n = words.size();
        for(auto [ch, cnt] : store)
            if((cnt - n) % n) return false;
        return true;
    }
};