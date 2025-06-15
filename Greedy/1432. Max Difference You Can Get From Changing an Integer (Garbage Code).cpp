class Solution {
public:
    int maxDiff(int num) 
    {
        auto s = to_string(num);
        set<char> st(begin(s), end(s));
        // unordered_set<char> st(begin(s), end(s));
        for(auto ch : st)
            cout<<ch<<", ";
        cout<<endl;
        
        auto mx = s, mn = s;
        for(auto ch : st)
        {
            auto temp = s;
            for(auto &c : temp)
            {
                if(ch == c)
                {
                    c = '9';
                }
            }
            mx = max(mx, temp);
            cout<<temp<<", ";
        }
        for(auto ch : st)
        {
            auto temp = s;
            for(auto &c : temp)
            {
                if(ch == c)
                {
                    c = '0';
                }
            }
            cout<<temp<<", ";
            if(temp[0] == '0') continue;
            mn = min(mn, temp);
        }
        for(auto ch : st)
        {
            auto temp = s;
            for(auto &c : temp)
            {
                if(ch == c)
                {
                    c = '1';
                }
            }
            cout<<temp<<", ";
            mn = min(mn, temp);
        }
        cout<<endl;
        cout<<mx<<" "<<mn<<endl;
        return stoi(mx) - stoi(mn);

        return -1;    
    }
};