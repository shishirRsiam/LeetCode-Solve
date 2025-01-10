class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        unordered_map<char, int> maxFreq;
        for(auto word : words2)
        {
            unordered_map<char, int> count;
            for(auto ch : word)
            {
                count[ch] += 1;
                maxFreq[ch] = max(maxFreq[ch], count[ch]);
            }
        }  

        vector<string> ans;
        for(auto word : words1)
        {
            unordered_map<char, int> count;
            for(auto ch : word) count[ch] += 1;

            bool isUniversal = true;
            for(auto [ch, maxCount] : maxFreq)
            {
                if(count[ch] < maxCount) isUniversal = false;
                if(not isUniversal) break;
            }
            if(isUniversal) ans.push_back(word);
        }
        return ans;  
    }
};