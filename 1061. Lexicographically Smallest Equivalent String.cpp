class Solution {
public:
    char dfs(char ch, unordered_map<char, vector<char>> &store, unordered_set<char> &visited)
    {
        if (visited.count(ch)) return ch;
        visited.insert(ch);

        if(store[ch].empty()) return ch;

        char new_ch = ch;
        for(char child : store[ch])
        {
            char candidate = dfs(child, store, visited);
            if(candidate < new_ch)
                new_ch = candidate;
        }

        return new_ch;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        int n = s1.size();
        unordered_map<char, vector<char>> store;
        for(int i = 0; i < n; i++)
        {   
            store[s1[i]].push_back(s2[i]);
            store[s2[i]].push_back(s1[i]);
        }    

        string ans;
        for(auto ch : baseStr)
        {
            unordered_set<char> visited;
            ans += dfs(ch, store, visited);
        }

        return ans;
    }
};