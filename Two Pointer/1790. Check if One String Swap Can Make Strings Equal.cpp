class Solution {
public:
    bool areAlmostEqual(string s1, string s2) 
    {
        if(s1 == s2) return true;

        int i = 0, n = max(s1.size(), s2.size());  
        while(i < n and s1[i] == s2[i]) i++;

        int j = i + 1;
        while(j < n and s1[j] == s2[j]) j++;
        
        swap(s1[i], s1[j]);

        return s1 == s2;
    }
};