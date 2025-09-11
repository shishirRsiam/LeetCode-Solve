class Solution {
public:
    string sortVowels(string s) 
    {
        string v;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') v+=ch;
        }

        if(v.empty()) return s;
        
        int k = 0;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            char &ch = s[i];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') 
            {
                ch = v[k];
                k++;
            }
        }
        return s;
    }
};