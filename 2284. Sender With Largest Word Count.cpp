class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) 
    {
        unordered_map<string, int> store;
        int n = messages.size(), maxMessageCount = 0;
        
        for(int i = 0; i < n; i++)
        {
            int cnt = count(begin(messages[i]), end(messages[i]), ' ');
            store[senders[i]] += cnt + 1;
            maxMessageCount = max(maxMessageCount, store[senders[i]]);
        }

        string maxMessageSender;
        for(auto [sender, count] : store)
            if(count == maxMessageCount and maxMessageSender < sender)
                maxMessageSender = sender;

        return maxMessageSender;
    }
};