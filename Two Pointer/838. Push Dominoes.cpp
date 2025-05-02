class Solution {
public:
    string pushDominoes(string s) 
    {
        int i = 0, j = 0, n = s.size();
        i = n - 1;

        while(i >= 0 and s[i] == '.') i--;
        if(i >= 0 and s[i] == 'R')
            while(i < n) s[i++] = 'R';

        i = j = 0;
        while(i < n and s[i] == '.') i++;
        if(s[i] == 'L')
            while(j < i) s[j++] = 'L';

        i = j = 0;
        int count = 0;
        while(j < n)
        {
            if(s[j] == '.') count += 1;
            else 
            {
                int mid = count / 2;
                if(s[i] == s[j]) 
                {
                    mid = count;
                    for(int cur = i; cur <= mid + i; cur++)
                        s[cur] = s[i];
                }
                else if(s[i] == 'R' and s[j] == 'L')
                {
                    int temp = mid + 1;
                    while(temp--)
                        s[i + temp] = s[i];

                    temp = i + mid + 1;
                    temp += count % 2;
                    while(temp < j)
                        s[temp++] = s[j];
                }
                i = j;
                count = 0;
            }
            j++;
        }
        return s;
    }
};