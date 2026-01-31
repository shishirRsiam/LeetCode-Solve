class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char t) 
    {
        char a = l[0];
        for(int i=0;i<l.size();i++)
        {
            if(l[i] > t)
            {
                a = l[i];
                break;
            }
        }
        return a;
    }
};