class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
    {
        string word, vowel = "aeiou";
        vector<int> prefixSum(1), ans;
        int sumCount = 0, n = words.size();
        for(int i=0;i<n;i++)
        {
            word = words[i];
            if(vowel.find(word[0]) != -1 and vowel.find(word.back()) != -1)
                sumCount += 1;
            prefixSum.push_back(sumCount);
        }

        for(auto vec:queries)
        {
            int l = vec[0], r = vec[1]+1;
            ans.push_back(prefixSum[r] - prefixSum[l]);
        }
        return ans;
    }
};