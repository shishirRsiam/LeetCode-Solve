class Solution {
public:
    bool hasMatch(string s, string p) 
    {
        int star = p.find('*');
        string s1 = p.substr(0, star), s2 = p.substr(star + 1);
        if(not s1.size() or s.find(s1) != -1)
        {
            s = s.substr(s.find(s1) + s1.size());
            if(not s2.size() or s.find(s2) != -1) return true;
        }
        return false;    
    }
};