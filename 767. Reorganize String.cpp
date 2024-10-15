class Solution
{
public:
    string reorganizeString(string s)
    {
        unordered_map<int, int> mp;
        for (auto ch : s)
            mp[ch]++;

        priority_queue<pair<int, char>> pq;
        for (auto [key, count] : mp)
            pq.push({count, key});

        string ans;
        while (!pq.empty())
        {
            auto [count, key] = pq.top();
            pq.pop();
            if (ans.size() and ans.back() == key)
                return "";
            ans += key;
            count--;
            if (!pq.empty())
            {
                auto [count2, key2] = pq.top();
                pq.pop();
                ans += key2;
                count2--;
                if (count2)
                    pq.push({count2, key2});
            }

            if (count)
                pq.push({count, key});
        }
        return ans;
    }
};