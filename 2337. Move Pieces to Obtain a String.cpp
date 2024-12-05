class Solution {
public:
    bool canChange(string start, string target) 
    {
        int idx = 0, cur = 0, n = start.size();

        for(int i = 0; i < n; i++)
        {
            if(start[i] == target[i]) continue;
            
            cur = max(cur, i + 1);
            if(start[i] == '_')
            {
                while(cur < n)
                {
                    if(start[cur] == 'R') return false;
                    if(start[cur] == 'L')
                    {
                        swap(start[i], start[cur++]);
                        break;
                    }
                    cur++;
                }
            }
            
            if(start[i] == 'R')
            {
                while(cur < n)
                {
                    if(start[cur] == 'L') return false;
                    if(start[cur] == '_')
                    {
                        swap(start[i], start[cur++]);
                        break;
                    }
                    cur++;
                }
            }
            // cout<<i<<": "<<start<<endl;
        }
        // cout<<start<<endl<<target<<endl;
        return start == target;
    }
};