class Solution {
public:
    bool canBeValid(string s, string locked) 
    {
        if(s.size() % 2) return false;
        
        int count = 0, changes = 0, n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(locked[i] == '0') changes += 1;
            else 
            {
                if(s[i] == '(') count += 1;
                else 
                {
                    if(count) count -= 1;
                    else if(changes) changes -= 1;
                    else return false;
                }
            }
        }
        count = 0, changes = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(locked[i] == '0') changes += 1;
            else 
            {
                if(s[i] == ')') count += 1;
                else 
                {
                    if(count) count -= 1;
                    else if(changes) changes -= 1;
                    else return false;
                }
            }
        }
        return true;
    }
};