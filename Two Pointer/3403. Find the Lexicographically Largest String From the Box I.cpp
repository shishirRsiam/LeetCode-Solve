class Solution {
public:
    string answerString(string word, int numFriends) 
    {
        if(numFriends == 1) return word;

        int n = word.size();
        int max_length = n - numFriends + 1;

        int largest_char_index = 0;
        for(int i = 0; i < n; i++)
        {
            if(word[largest_char_index] < word[i])
                largest_char_index = i;
        }

        string ans;
        for(int i = 0; i < n; i++)
        {
            if(word[i] != word[largest_char_index]) continue;
            ans = max(ans, word.substr(i, max_length));
        }
        return ans;
    }
};