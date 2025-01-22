class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) 
    {
        unordered_map<char, int> count;
        unordered_map<int, vector<string>> store;
        for(auto ch : licensePlate) count[tolower(ch)] += 1;

        string ans = "zzzzzzzzzzzzzzzzzzzz";
        for(auto word : words)
        {
            bool flag = true;
            unordered_map<char, int> wordCount;
            for(auto ch : word) wordCount[tolower(ch)] += 1;
            for(auto[ch, cnt] : count)
            {
                if(isalpha(ch) and wordCount[ch] < cnt)
                {
                    flag = false;
                    break;
                }
            }
            if(flag) 
            {
                if(ans.size() > word.size()) ans = word;
                else if(ans.size() == word.size())
                    ans = min(ans, word);
                store[ans.size()].push_back(word);
            }
        }
        return store[ans.size()][0]; 
    }
};