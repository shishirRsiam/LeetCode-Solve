class Solution {
public:
    bool isLongPressedName(string name, string typed) 
    {
        int i = 0, j = 0, n = name.size(), m = typed.size();
        while(j < m)
        {
            if(name[i] == typed[j]) i++, j++;
            else if(i and typed[j] == name[i - 1]) j++;
            else break;
        }
        return i == n and j == m;
    }
};